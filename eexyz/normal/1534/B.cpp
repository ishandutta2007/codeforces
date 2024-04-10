#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1000005
int n,i,j,T,f[3],m,x,y,v,a[N]; 
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;ans=0;a[n+1]=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)ans+=abs(a[i]-a[i-1]);
		ans+=a[n];
		for(i=1;i<=n;++i){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				ans-=min(a[i]-a[i-1],a[i]-a[i+1]);
			}
		}
		cout<<ans<<"\n";
	}
}