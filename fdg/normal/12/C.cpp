#include <cstdio>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <int> pr(n,0);
	for(int i=0;i<n;i++)
		cin >> pr[i];
	map <string,int> f;
	set <string> s;
	for(int i=0;i<m;i++)
	{
		string a;
		cin >> a;
		a=a.c_str();
		if (f.count(a)) f[a]=f[a]+1;
		else f[a]=1;
		s.insert(a);
	}
	int mnPr=0,mxPr=0;
	sort(pr.begin(),pr.end());
	vector <int> d;
	for(set <string> :: iterator it=s.begin();it!=s.end();it++)
	{
		d.push_back(f[it->c_str()]);
	}
	sort(d.rbegin(),d.rend());
	for(int i=0;i<d.size();i++)
		mnPr+=d[i]*pr[i];
	sort(pr.rbegin(),pr.rend());
	for(int i=0;i<d.size();i++)
		mxPr+=d[i]*pr[i];
	cout << mnPr << " " << mxPr << endl;
	return 0;
}