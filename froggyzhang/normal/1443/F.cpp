#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int T,n,m,a[N],b[N],p[N],vis[N];
set<int> s,t;
int Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[a[i]]=i;
		vis[i]=0;
		t.insert(i);
	}
	for(int i=1;i<=m;++i){
		b[i]=read();
		vis[b[i]]=1;
	}
	s.clear();
	for(int i=1;i<=n;++i){
		if(!vis[a[i]])s.insert(i);
	}
	s.insert(0),s.insert(n+1);
	t.insert(0),t.insert(n+1);
	int ans=1;
	for(int i=1;i<=m;++i){
		int u=p[b[i]];
		int r=*s.upper_bound(u);
		int l=*--s.lower_bound(u);
		int R=*t.upper_bound(u);
		int L=*--t.lower_bound(u);
		int cnt=(l>=1&&l==L)+(r<=n&&r==R);
		if(!cnt)return 0;
		ans=ans*cnt%mod;
		if(l>=1&&l==L)s.erase(l),t.erase(l);
		else s.erase(r),t.erase(r);
		s.insert(u);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}