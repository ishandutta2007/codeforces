#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int T,n,m,i,j,k,x,y,a[N],p[N],s[N],ans; 
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;ans=n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)p[i]=p[i-1]+(a[i]==1);
		s[n+1]=0;
		for(i=n;i;--i)s[i]=s[i+1]+(a[i]==0);
		for(i=0;i<=n;++i){
			ans=min(ans,p[i]+max(s[i+1]-p[i],0));
		}
		cout<<ans<<"\n";
	}
}