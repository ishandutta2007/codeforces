#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define N 200020
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
int T,n,a[N],suf[N],nxt[N],pre[N],las[N],A[N],B[N];
int st[N],top;
map<int,int> mp;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		nxt[i]=n+1,las[i]=0;
	}
	suf[n+1]=-1;
	for(int i=n;i>=1;--i){
		suf[i]=max(suf[i+1],a[i]);
	}
	pre[0]=-1;
	for(int i=1;i<=n;++i){
		pre[i]=max(pre[i-1],a[i]);
	}
	top=0;
	for(int i=n;i>=1;--i){
		while(top&&a[i]<=a[st[top]])--top;
		if(top)nxt[i]=st[top];
		st[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]<=a[st[top]])--top;
		if(top)las[i]=st[top];
		st[++top]=i;
	}
	mp.clear();
	for(int i=1;i<=n;++i){
		if(mp.count(a[i]))A[i]=mp[a[i]];
		else A[i]=-1;
		mp[pre[i]]=i;
	} 
	mp.clear();
	for(int i=n;i>=1;--i){
		if(mp.count(a[i]))B[i]=mp[a[i]];
		else B[i]=n+2;
		mp[suf[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int l=A[i],r=B[i];
		if(las[i]<=l&&nxt[i]>=r){
			printf("YES\n%d %d %d\n",l,r-l-1,n-r+1);
			return;
		}
	}
	printf("NO\n");
}	
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}