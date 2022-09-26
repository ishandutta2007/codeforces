#include<bits/stdc++.h>
using namespace std;
#define N 4020
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
int T,n,w[N][N];
int a[N][N],b[N][N],ta[N],tb[N],kb[N][N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			w[i][j]=read();
		}
	}
	printf("B\n");
	fflush(stdout);
	char opt[3];
	scanf("%s",opt);
	int u=read();
	if((opt[0]=='I')^(u>n)){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				w[i][j]=-w[i][j];
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		ta[i]=tb[i]=0;
		q.push(i); 
		for(int j=1;j<=n;++j){
			a[i][j]=j;
			b[i][j]=j;
		}
		sort(a[i]+1,a[i]+n+1,[&](int x,int y){return w[i][x]>w[i][y];});
		sort(b[i]+1,b[i]+n+1,[&](int x,int y){return w[x][i]<w[y][i];});
		for(int j=1;j<=n;++j){
			kb[i][b[i][j]]=j;
		}
	}
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for(int u=1;u<=n;++u){
			int j=a[i][u];
			if(!tb[j]){
				tb[j]=i,ta[i]=j;break;
			}
			if(kb[j][i]<kb[j][tb[j]]){
				q.push(tb[j]),tb[j]=i,ta[i]=j;break;
			}
		}
	}
	while(u>0){
		printf("%d\n",u>n?tb[u-n]:ta[u]+n);
		fflush(stdout);
		u=read();
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}