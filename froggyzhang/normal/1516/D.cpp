#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,Q,nxt[N][20],las[N],a[N];
void Split(int p,int x){
	nxt[p][0]=n+1;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			while(x%i==0)x/=i;
			nxt[p][0]=min(nxt[p][0],las[i]);
			las[i]=p;
		}
	}
	if(x>1){
		nxt[p][0]=min(nxt[p][0],las[x]);
		las[x]=p;
	}
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=100000;++i)las[i]=n+1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=n;i>=1;--i){
		Split(i,a[i]);
	}
	nxt[n+1][0]=n+1;
	for(int i=n;i>=1;--i){
		nxt[i][0]=min(nxt[i][0],nxt[i+1][0]);
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i<=n+1;++i){
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		}
	}
	while(Q--){
		int l=read(),r=read();
		int ans=0;
		for(int i=18;i>=0;--i){
			if(nxt[l][i]<=r)ans|=1<<i,l=nxt[l][i];
		}
		++ans;
		printf("%d\n",ans);
	}
	return 0;
}