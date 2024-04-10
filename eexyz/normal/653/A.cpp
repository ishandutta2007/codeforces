#include<bits/stdc++.h>
using namespace std;
int n,i,x,v[109905];
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>x,v[x]=1;
	for(i=1;i<=1000;++i)if(v[i]&&v[i+1]&&v[i+2])return cout<<"YES\n",0;
	cout<<"NO\n";
}