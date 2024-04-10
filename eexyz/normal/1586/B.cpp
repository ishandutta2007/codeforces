#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,i,j,x,y,a,b,c,T,l,r,s,fl;
int check(int x){
	for(i=2;i<x;++i){
		if(x%i==0)return 1;
	}
	return 0;
}
int m,vis[1000005];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)vis[i]=0;
		for(i=1;i<=m;++i){
			cin>>a>>b>>c;vis[b]=1;
		}
		for(i=1;i<=n;++i){
			if(!vis[i]){
				for(j=1;j<=n;++j){
					if(i!=j)cout<<i<<' '<<j<<'\n';
				}
				break;
			}
		}
	} 
}