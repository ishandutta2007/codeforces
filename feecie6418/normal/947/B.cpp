#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1e6;
int n;
ll v[100005],t[100005],pret[100005],sufv[100005],nwv[100005],mlt[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=n;i;i--)sufv[i]=sufv[i+1]+v[i];
	for(int i=1;i<=n;i++)pret[i]=pret[i-1]+t[i];
	for(int i=1;i<=n;i++)nwv[i]=v[i]+pret[i-1];
	sort(nwv+1,nwv+n+1);
	ll curdel=0,sum=0;
	for(int i=1,j=0;i<=n;i++){
		curdel+=t[i];
		while(j<n&&nwv[j+1]<=curdel)j++,sum+=nwv[j];
		mlt[i]=sum+curdel*(n-j);
		cout<<mlt[i]-mlt[i-1]-t[i]*(n-i)<<' ';
	}
}