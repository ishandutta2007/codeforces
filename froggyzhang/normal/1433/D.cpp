#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 5005
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
int T,n,a[N],vis[N];
queue<int> q;
void Solve(){
	bool same=true;
	for(int i=2;i<=n;++i){
		if(a[i]^a[1]){
			same=false;break;
		}
	}
	if(same){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	q.push(1);
	vis[1]=1;
	for(int i=2;i<=n;++i)vis[i]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			if(a[i]^a[u]){
				q.push(i),vis[i]=1;
				printf("%d %d\n",i,u);
			}
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		Solve();
	}
	return 0;
}