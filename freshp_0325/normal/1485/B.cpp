#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,q,k,a[100005],decs[100005];
int main(){
	cin>>n>>q>>k;
	for(LL i=1;i<=n;++i)	cin>>a[i];
	a[n+1]=k+1;
	for(LL i=1;i<=n;++i)	decs[i]=a[i+1]-a[i-1]-2;
	for(LL i=1;i<=n;++i)	decs[i]+=decs[i-1];
	while(q-->0)
	{
		LL l,r;
		cin>>l>>r;
		if(l==r)	cout<<k-1<<endl;
		else if(l+1==r)
		{
			r=a[r],l=a[l];
			cout<<r-2+(k-l-1)<<endl;
		}
		else
		{
			cout<<(a[l+1]-2+(k-a[r-1]-1)+decs[r-1]-decs[l])<<endl;
		}
	}
	return 0;
}