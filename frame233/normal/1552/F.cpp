#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int f[N],x[N],y[N],s[N],sum[N],t[N],pos,id[N],type[N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(x[i],y[i],s[i]),t[++pos]=x[i],t[++pos]=y[i];
	std::sort(t+1,t+pos+1);
	for(int i=1;i<=n;++i){
		x[i]=std::lower_bound(t+1,t+pos+1,x[i])-t;id[x[i]]=i,type[x[i]]=0;
		y[i]=std::lower_bound(t+1,t+pos+1,y[i])-t;id[y[i]]=i,type[y[i]]=1;
	}
	for(int p=1;p<=pos;++p){
		sum[p]=sum[p-1];
		if(type[p]==0){
			int i=id[p];
			f[i]=t[x[i]]-t[y[i]]+sum[x[i]]-sum[y[i]],f[i]%=mod,add(f[i],mod),add(sum[p],f[i]);
		}
	}
	int ans=t[x[n]]+1;if(ans>=mod)ans-=mod;
	for(int i=1;i<=pos;++i)if(s[i]==1)add(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}