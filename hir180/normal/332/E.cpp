#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
string p,a;
int k;
string s[2005]={};
int main()
{
	getline(cin, p, '\n');
	getline(cin, a, '\n');

	cin >> k;
	map<string,vector<int> >ma;
	for(int i=0;i<p.size();i++)
	{
		s[i%k]+=p[i];
	}
	for(int i=0;i<k;i++)
	{
		ma[s[i]].push_back(i);
	}
	vector<int>ans;
	for(int i=1;i<=min((int)a.size(),k);i++)
	{
		string v[205]={};
		for(int j=0;j<a.size();j++)
		{
			v[j%i]+=a[j];
		}
		vector<int>up;
		int prev=1e8;
		for(int j=i-1;j>=0;j--)
		{
			if(ma[v[j]].empty()) goto fail;
			vector<int>sa=ma[v[j]];
			int g=lower_bound(sa.begin(),sa.end(),prev)-sa.begin();
			g--;
			if(g<0) goto fail;
			up.push_back(sa[g]);
			prev=sa[g];
		}
		if(!ans.size())
		{
			ans=up;
			goto fail;
		}
		for(int i=ans.size()-1;i>=0;i--)
		{
			if(ans[i]>up[i+up.size()-ans.size()]) goto fail;
			if(ans[i]<up[i+up.size()-ans.size()])
			{
				ans=up;
				goto fail;
			}
		}
		fail:;
	}
	if(ans.empty()) cout << "0" << endl;
	else
	{
		string ret="";
		reverse(ans.begin(),ans.end());
		int cur=0;
		for(int i=0;i<k;i++)
		{
			if(cur<ans.size() && ans[cur]==i) ret+='1';
			else ret+='0';
			if(ret[ret.size()-1]=='1') cur++;
		}
		cout << ret << endl;
	}
}