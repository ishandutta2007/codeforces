#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
void MAIN(){
	int n,c;read(n,c);std::multiset<ll> S;ll x;
	for(int i=1;i<=n;++i)read(x),S.insert(x);
	int ans=0;
	while(!S.empty()){
		ll x=*S.begin();S.erase(S.begin());
		auto it=S.find(x*c);
		if(it!=S.end())S.erase(it);
		else ++ans;
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}