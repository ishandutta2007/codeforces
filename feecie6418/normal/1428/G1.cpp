#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int K,q;
ll g[1000005],f[6];
int main(){
	cin>>K,memset(g,0xc0,sizeof(g)),g[0]=0;
	for(int i=0;i<6;i++)cin>>f[i];
	for(int i=0,p=3;i<6;i++,p*=10){
		int u=3*(K-1),j=1,t=1;
		while(t<=u){
			for(int k=999999;k>=1ll*p*j;k--)g[k]=max(g[k],f[i]*j+g[k-p*j]);
			j*=2,t+=j;
		}
		if(t>u){
			t-=j,j=u-t;
			for(int k=999999;k>=1ll*p*j;k--)g[k]=max(g[k],f[i]*j+g[k-p*j]);
		}
	}
	for(int i=0,p=1;i<6;i++,p*=10){
		for(int k=999999;k>=0;k--){
			for(int j=1;j<=9&&j*p<=k;j++)g[k]=max(g[k],g[k-j*p]+(j%3?0:(j/3)*f[i]));
		}
	}
	cin>>q;
	while(q--){
		int x;
		cin>>x,cout<<g[x]<<'\n';
	}
}