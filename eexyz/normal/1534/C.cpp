#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1000005
int n,i,j,T,f[N],m,x,y,v,a[N]; 
long long ans;
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)f[i]=i;ans=1;
		for(i=1;i<=n;++i){
			cin>>x;
			if(find(x)!=find(a[i])){
				f[find(x)]=find(a[i]);
			}
			else ans=(ans*2)%mod;
		}
	cout<<ans<<'\n';
	}
}