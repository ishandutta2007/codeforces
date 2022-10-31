#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int a[N];
void MAIN(){
	int n;read(n);ll s=0;std::multiset<ll> S;
	for(int i=1;i<=n;++i)read(a[i]),s+=a[i],S.insert(a[i]);
	std::multiset<ll> cur;
	auto ins=[&](ll x){auto it=S.find(x);if(it!=S.end())S.erase(it);else cur.insert(x);};
	ins(s);
	for(int i=0;i<n-1&&!cur.empty();++i){
		ll x=*--cur.end();cur.erase(--cur.end());
		ll a=x/2,b=x-a;ins(a),ins(b);
	}
	puts(cur.empty()&&S.empty()?"YES":"NO");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}