#include<bits/stdc++.h>
using namespace std;
#define N 55
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
bool Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	int R=-1,W=-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(mp[i][j]=='R'){
				if(~R){
					if(R^((i+j)&1))return false;
				}
				else R=(i+j)&1;
			}
			else if(mp[i][j]=='W'){
				if(~W){
					if(W^((i+j)&1))return false;
				}
				else W=(i+j)&1;
			}
		}
	}
	if(~R&&~W&&R==W)return false;
	if(!~R&&!~W)R=0,W=1;
	else if(!~R)R=W^1;
	else if(!~W)W=R^1;
	printf("YES\n");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			putchar(((i+j)&1)==R?'R':'W');		
		}
		putchar('\n');
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		if(!Solve())printf("NO\n");
	}
	return 0;
}