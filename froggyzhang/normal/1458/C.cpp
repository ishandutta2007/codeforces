#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,a[N][N],n,m,b[N][N];
char s[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();			
		}
	}
	scanf("%s",s+1);
	int t[3]={0,0,0};
	int g[3]={0,1,2};
	for(int i=1;i<=m;++i){
		if(s[i]=='L'){
			--t[g[1]];
		}
		else if(s[i]=='R'){
			++t[g[1]];
		}
		else if(s[i]=='U'){
			--t[g[0]];
		}
		else if(s[i]=='D'){
			++t[g[0]];
		}
		else if(s[i]=='I'){
			swap(g[1],g[2]);
		}
		else{
			swap(g[0],g[2]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int p[3]={0,0,0};
			for(int k=0;k<3;++k){
				if(g[k]==2)p[k]=((a[i][j]+t[2])%n+n-1)%n+1;	
			}
			for(int k=0;k<3;++k){
				if(g[k]==0)p[k]=((i+t[0])%n+n-1)%n+1;	
			}
			for(int k=0;k<3;++k){
				if(g[k]==1)p[k]=((j+t[1])%n+n-1)%n+1;	
			}
			b[p[0]][p[1]]=p[2];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}