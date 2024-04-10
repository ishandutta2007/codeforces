#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=2000005;typedef long long ll;
int a[N],LB[N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=n;i>=1;--i)LB[a[i]]=i;
	LB[2000001]=n+1;for(int i=2e6;i>=0;--i)if(!LB[i])LB[i]=LB[i+1];
	for(int t=1;;++t)if(1LL*t*t+t>=a[1]){
		ll v=1LL*t*t,l=std::max(0LL,v-a[1]),r=v+t-a[1],R=r-l,L=0;int cur=t;
		while(true){
			ll nxt=1LL*(cur+1)*(cur+1);
			int p=nxt-r>2e6?n:LB[nxt-r]-1;
			chmin(R,1LL*cur*(cur+1)-(a[p]+l));
			++p;if(p>n)break;
			chmax(L,nxt-(a[p]+l)),++cur;
		}
		if(L<=R)return printf("%lld\n",L+l),0;
	}
	return 0;
}