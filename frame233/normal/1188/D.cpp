#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005;typedef long long ll;
ll a[N];int f[N],g[N],t1[N],t2[N],I,pre[N][2],suf[N][2];
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	ll mx=*std::max_element(a+1,a+n+1);
	for(int i=1;i<=n;++i)a[i]=mx-a[i];
	std::iota(t1+1,t1+n+1,1),memset(f,63,sizeof(f)),f[n+1]=0;
	for(int t=0;t<60;++t){
		memset(g,63,sizeof(g));
		for(int i=1;i<=n;++i)pre[i][0]=pre[i-1][0],pre[i][1]=pre[i-1][1],++pre[i][a[t1[i]]>>t&1];
		for(int i=n;i>=1;--i)suf[i][0]=suf[i+1][0],suf[i][1]=suf[i+1][1],++suf[i][a[t1[i]]>>t&1];
		for(int j=1,p;j<=n+1;++j){
			p=suf[j][1],chmin(g[n+1-p],f[j]+pre[j-1][1]+suf[j][0]);
			p=pre[j-1][1]+suf[j][0]+suf[j][1],chmin(g[n+1-p],f[j]+pre[j-1][0]+suf[j][1]);
		}
		memcpy(f,g,sizeof(f));
		int pos=0;for(int i=1;i<=n;++i)if(!(a[t1[i]]>>t&1))t2[++pos]=t1[i];
		for(int i=1;i<=n;++i)if(a[t1[i]]>>t&1)t2[++pos]=t1[i];
		memcpy(t1,t2,(n+3)<<2);
	}
	printf("%d\n",f[n+1]);
	return 0;
}