#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,res;
vector<tuple<int,int,int>>s;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>j>>k,s.push_back({max(j,k),j,k});
	sort(s.begin(),s.end());
	for(auto [i,k,j]:s)
		if(k>=m)
			m=max(m,j),res++;
	cout<<res;
}