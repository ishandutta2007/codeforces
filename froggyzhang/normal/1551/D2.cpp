#include<bits/stdc++.h>
using namespace std;
#define N 123
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
int T,n,m,K;
char a[N][N];
inline int Get(int x,int y){
	bitset<26> vis;
	vis.reset();
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			if(isalpha(a[x+i][y+j]))vis[a[x+i][y+j]-'a']=1;
		}
	}
	for(int i=0;i<26;++i){
		if(!vis[i])return i;
	}
	return -1;
}
void Solve(){
	n=read(),m=read(),K=read();
	bool flag=0;
	if(n&1)swap(n,m),K=n*m/2-K,flag=1;
	if((((m+1)/2)*n-K)&1||K>(m/2)*n){printf("NO\n");return;}
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;++i){
			if(K){
				a[i][j]=a[i][j+1]='a'+Get(i,j);
				--K;
			}
			else{
				a[i][j]=a[i+1][j]='a'+Get(i,j);
				if(j<m)a[i][j+1]=a[i+1][j+1]='a'+Get(i,j+1);
				++i;
			}
		}	
	}
	printf("YES\n");
	if(flag){
		static char tmp[N][N];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				tmp[j][i]=a[i][j];
			}
		}
		memcpy(a,tmp,sizeof(a));
		swap(n,m);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			putchar(a[i][j]);
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