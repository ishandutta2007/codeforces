#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int T,n;
char mp[N][N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	int x[2]={0,0},y[2]={0,0};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(mp[i][j]=='*'){
				if(!x[0])x[0]=i,y[0]=j;
				else x[1]=i,y[1]=j;
			}
		}
	}
	if(x[0]==x[1])x[1]=x[0]%n+1;
	if(y[0]==y[1])y[1]=y[0]%n+1;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			mp[x[i]][y[j]]='*';
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			putchar(mp[i][j]);
		}
		putchar('\n');
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}