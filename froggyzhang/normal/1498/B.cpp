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
int T,n,W,a[N];
multiset<int> s;
int Solve(){
	n=read(),W=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	s.clear();
	int ans=0;
	for(int i=1;i<=n;++i){
		if(s.empty()||(*--s.end())<a[i])++ans,s.insert(W);
		auto it=s.lower_bound(a[i]);
		int tp=(*it)-a[i];
		s.erase(it);
		s.insert(tp);
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