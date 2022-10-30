#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int to[N],c[N],Y[N];
void upd(int x,int C){for(;x;x-=lowbit(x))add(c[x],C);}
int ask(int x){int ans=0;for(;x<N;x+=lowbit(x))add(ans,c[x]);return ans;}
int main(){
	int n;read(n);
	for(int i=1,x,y;i<=n;++i)read(x,y),to[x]=y,Y[i]=y;
	std::set<int> S={0};int k;read(k);for(int i=1,x;i<=k;++i)read(x),S.insert(Y[x]);
	int ans=0;
	for(int i=1;i<=n+n;++i)if(to[i]){
		int val=ask(to[i])+(to[i]<=*--S.end());val%=mod;
		upd(to[i],val),add(ans,val),S.erase(to[i]);
	}
	printf("%d\n",ans);
	return 0;
}