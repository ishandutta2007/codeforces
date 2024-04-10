#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=50005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
int f[1<<10],g[1<<10],can[10];
int main(){
	int n,m;read(n,m);
	for(int i=1,x,y;i<=m;++i)read(x,y),can[x]|=1<<y,can[y]|=1<<x;
	f[0]=1;
	for(int i=n;i>=1;--i){
		memset(g,0,sizeof(g));
		for(int st=0;st<1<<10;++st)if(f[st]){
			for(int j=0;j<10;++j)if(!((st&can[j])&((1<<j)-1)))add(g[1<<j|(st&can[j])],f[st]);
		}
		memcpy(f,g,sizeof(f));
	}
	int ans=0;for(int i=0;i<1<<10;++i)add(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}