#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int T,n,m,i,j,k,x,y,a[N],p[N],f[N],s[N],ans; 
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)f[a[i]]=i+1;
		for(i=1;i<=n;++i)f[a[n]]=1;
		for(i=1;i<=n;++i)cout<<f[i]<<" ";cout<<"\n";
	}
}