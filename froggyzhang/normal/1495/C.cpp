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
int T,n,m;
char mp[N][N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	if(n==1||n==2){
		for(int i=1;i<=m;++i){
			mp[1][i]='X';
		}
	}
	else if(n==3){
		for(int i=1;i<=m;++i){
			mp[2][i]='X';
		}
	}
	else{
		int r=n/3*3;
		for(int i=1;i<=r;i+=3){
			for(int j=1;j<=m;++j){
				mp[i][j]='X';
			}
			bool flag=0;
			for(int j=1;j<=m&&!flag;++j){
				if((i+1<=n&&mp[i+1][j]=='X')||(i+2<=n&&mp[i+2][j]=='X')){
					mp[i+1][j]=mp[i+2][j]='X',flag=1;
					break;
				}
			}
			if(!flag){
				mp[i+1][m]=mp[i+2][m]='X';
			}
		}
		if(n==r){
			for(int i=1;i<=m;++i){
				mp[n][i]=='X'?(mp[n-1][i]='X'):1;
			}
		}
		if(n==r+1||n==r+2){
			for(int i=1;i<=m;++i){
				mp[n-(n==r+2)][i]='X';
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
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