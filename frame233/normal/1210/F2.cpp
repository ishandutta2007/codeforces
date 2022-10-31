#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int mod=1000000007;typedef __uint128_t ULL;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int n,p[7][7],coef[7][1<<7];std::map<ULL,int> f[10];int vec[35],pos;ULL g[128][128];
int main(){
	read(n);ll inv=ksm(100);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)read(p[i][j]),p[i][j]=inv*p[i][j]%mod;
		for(int st=0;st<1<<n;++st){
			coef[i][st]=1;
			for(int j=0;j<n;++j)coef[i][st]=1LL*(st>>j&1?p[i][j]:mod+1-p[i][j])*coef[i][st]%mod;
		}
	}
	for(int st=1;st<1<<n;++st){
		for(int i=0;i<1<<n;++i){
			ULL to=0;for(int j=0;j<n;++j)if((st>>j&1)&&!(i>>j&1))to|=(ULL)1<<(i|(1<<j));
			g[st][i]=to;
		}
	}
	f[0][1]=1;
	for(int dep=0;dep<n;++dep){
		for(const auto &it:f[dep]){
			ULL cur=it.first;pos=0;
			for(int i=0;i<1<<n;++i)if(cur>>i&1)vec[pos++]=i;
			for(int st=1;st<1<<n;++st){
				ULL to=0;for(int i=0;i<pos;++i)to|=g[st][vec[i]];
				add(f[dep+1][to],1ULL*coef[dep][st]*it.second%mod);
			}
		}
	}
	int ans=0;for(const auto &it:f[n])if(it.first>>((1<<n)-1)&1)add(ans,it.second);
	printf("%d\n",ans);
	return 0;
}