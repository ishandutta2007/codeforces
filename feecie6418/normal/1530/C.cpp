#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],c[500005],d[500005];
bool F(int x){
	for(int i=1;i<=n;i++)c[i]=a[i],d[i]=b[i];
	for(int i=n+1;i<=n+x;i++)c[i]=100,d[i]=0;
	sort(c+1,c+n+x+1),sort(d+1,d+n+x+1);
	int u=(n+x)-(n+x)/4,s1=0,s2=0;
	for(int i=n+x;i>n+x-u;i--)s1+=c[i],s2+=d[i];
	if(s1>=s2)return 1;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		int l=0,r=4*n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(F(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
}