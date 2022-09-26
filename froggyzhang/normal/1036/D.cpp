#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 300030
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
int n,m,ans;
ll sa[N],sb[N];
set<ll> s;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		sa[i]=sa[i-1]+read();
	}
	m=read();
	for(int i=1;i<=m;++i){
		sb[i]=sb[i-1]+read();
	}
	if(sa[n]^sb[m]){
		return !printf("-1\n");
	}
	for(int i=1;i<=n;++i){
		s.insert(sa[i]);
	}
	for(int i=1;i<=m;++i){
		if(s.count(sb[i]))++ans;
	}
	printf("%d\n",ans);
	return 0;
}