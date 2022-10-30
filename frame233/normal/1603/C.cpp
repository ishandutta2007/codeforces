#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=998244353;typedef std::pair<int,int> pi;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int a[N];
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	std::vector<pi> f,g;int ans=0;
	for(int i=n;i>=1;--i){
		g.clear();
		for(auto [x,y]:f){
			int t=(a[i]+x-1)/x,cur=a[i]/t;
			add(ans,1LL*y*i*(t-1)%mod);
			if(!g.empty()&&g.back().first==cur)g.back().second+=y;
			else g.pb({cur,y});
		}
		if(!g.empty()&&g.back().first==a[i])++g.back().second;
		else g.pb({a[i],1});
		f=g;
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}