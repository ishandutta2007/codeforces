/*#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
vector<int> v[100005]
int n, i, j, k, h, a1, a2, a3, m, used[100005], och[200005], col[100005], ans;
int main()
{
	cin>>n>>m;
	for(i=0; i<m; i++)
	{
		cin>>a1>>a2;
		v[a1].push_back(a2);
		v[a2].push_back(a1);
	}
}*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
vector<pair<int, int>> qw;
int n, b[1000005], ans,i, j, k, h, a1, a2, a3, cur, vs, tc, ts;
int main()
{
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>b[i];
	}
	cur=k;
	for(i=2; i<=10000; i++)
	{
		a2=0;
		if(cur%i==0)
		{
			a1=i;
			while(cur%i==0)
			{
				a2++;
				cur=cur/i;
				//cout<<cur<<endl;
			}
		}
		if(a2>0)
		{
			qw.push_back(make_pair(a1, a2));
		}
	}
	if(cur>1)
	{
		qw.push_back(make_pair(cur, 1));
	}
	vs=qw.size();
	//cout<<vs;
	for(i=0; i<vs; i++)
	{
		//cout<<qw[i].first<<' '<<qw[i].second<<' '<<endl;
	}
	for(i=0; i<vs; i++)
	{
		tc=0;
		for(j=0; j<n; j++)
		{
			ts=0;
			cur=b[j];
			for(h=0; h<qw[i].second; h++)
			{
				if(cur%qw[i].first!=0)
				{
					ts++;
				}
				cur=cur/qw[i].first;
			}
			if(ts==0)
			{
				tc++;
			}
		}
		if(tc==0)
		{
			ans++;
		}
	}
	if(ans==0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}