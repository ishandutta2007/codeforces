#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;const ll mod=762939453125LL;
inline ll mul(ll a,ll b){return (__int128)a*b%mod;}
ll v[18],phi[18],w[18][5];
void MAIN(){
	ll x;read(x);ll b=(-x*1000000LL)%(1<<17);b=(b+(1<<17))%(1<<17);if(b%5==0)b+=1<<17;
	ll y=(1000000LL*x+b)>>17,t=0,cur=1;
	for(int i=0;i<17;++i){
		for(int j=0;j<5;++j){
			ll tmp=mul(cur,w[i][j]);
			if(tmp%v[i+1]==y%v[i+1]){t+=j*phi[i],cur=tmp;break;}
		}
	}
	printf("%lld\n",t+17);
}
int main(){
	phi[0]=1,phi[1]=4,v[0]=1,v[1]=5;ll tmp=2;
	for(int i=2;i<=17;++i)phi[i]=phi[i-1]*5,v[i]=v[i-1]*5;
	for(int i=0;i<17;++i){
		w[i][0]=1;for(int j=1;j<5;++j)w[i][j]=mul(w[i][j-1],tmp);
		ll t=1;for(int j=phi[i+1]/phi[i];j>=1;--j)t=mul(t,tmp);
		tmp=t;
	}
	int _;read(_);
	while(_--)MAIN();
	return 0;
}