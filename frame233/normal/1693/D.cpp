#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int f[N],g[N],p[N];
int main(){
	int n;read(n);int cnt=0;ll ans=0;
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=n;i>=1;--i){
		f[i]=n+1,g[i]=0,++cnt;
		for(int j=i+1;j<=n;++j){
			int a=0,b=n+1;
			if(p[j-1]<p[j])a=f[j-1];
			if(g[j-1]<p[j])a=std::max(a,p[j-1]);
			if(p[j-1]>p[j])b=g[j-1];
			if(f[j-1]>p[j])b=std::min(b,p[j-1]);
			if(a!=f[j]||b!=g[j])f[j]=a,g[j]=b,cnt-=a==0&&b==n+1;
			else break;
		}
		ans+=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}