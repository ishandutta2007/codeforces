#include<bits/stdc++.h>
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
int T,n,a[N],nxt[N],las[N];
vector<int> ans;
set<int> s;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		nxt[i]=i+1,las[i]=i-1;
	}
	nxt[n]=1,las[1]=n;
	s.clear();
	ans.clear();
	for(int i=1;i<=n;++i){
		if(__gcd(a[i],a[nxt[i]])==1)s.insert(i);
	}
	int u=1;
	while(!s.empty()){
		auto it=s.lower_bound(u);
		if(it==s.end())it=s.begin();
		u=(*it);
		int v=nxt[u];
		ans.push_back(v);
		if(v==u)break;
		las[nxt[v]]=u;
		nxt[u]=nxt[v];
		if(s.count(v))s.erase(v);
		if(__gcd(a[u],a[nxt[u]])^1)s.erase(it);
		u=v+1;
	}
	printf("%d",(int)ans.size());
	for(auto x:ans)printf(" %d",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}