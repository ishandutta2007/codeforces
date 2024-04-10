#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
int n,m,seed,base,ret,p[200002],k[200002],b[200002],w[200002],O,pos,t[5000002],a[5000002],aa[5000002];
long long ans[2],cnt,f[200002];
inline int rnd(){
    ret=seed;
    seed=(1ll*seed*base+233)%M;
    return ret;
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i)p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();
	p[0]=0;
	for(re int i=1;i<=m;++i){
		seed=b[i],base=w[i];
    	for(re int j=p[i-1]+1;j<=p[i];++j)
        	t[j]=(rnd()%2),
        	a[j]=(rnd()%k[i])+1;
	}
	for(re int i=1;i<=n;++i)ans[t[i]]+=a[i],aa[i]=a[i];
	O=ans[1]<ans[0];
	for(re int i=1;i<=n;++i)if(t[i]==O){pos=i;break;}
	if(pos^1)--a[1];
	for(re int i=pos;i<=n;++i)
		if(t[i]==O)cnt+=a[i],a[i]=0;
		else{
			re long long x=min(1ll*a[i],cnt);
			a[i]-=x,cnt-=x;
		}
	for(re int i=1;i<=n;++i)
		if(t[i]==O)cnt+=a[i],a[i]=0;
		else{
			re long long x=min(1ll*a[i],cnt);
			a[i]-=x,cnt-=x;
		}
	for(re int i=pos;i<=n;++i)
		if(t[i]==O)cnt+=a[i],a[i]=0;
		else{
			re long long x=min(1ll*a[i],cnt);
			a[i]-=x,cnt-=x;
		}
	cnt=1;
	for(re int i=1;i<=n;++i)cnt=(((aa[i]-a[i])^(1ll*i*i))+1)%M*cnt%M;
	printf("%lld",cnt);
}