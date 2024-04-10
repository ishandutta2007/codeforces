#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],t,ans,tag[200002],b[200002];
const int M=998244353;
inline int ksm(re int x,re int y){
	re int ss=1;
	while(y){
		if(y&1)ss=1ll*ss*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ss;
} 
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)tag[i]=0;
		for(re int i=1;i<=n;++i)a[read()]=i;
		for(re int i=1;i<=m;++i)b[i]=a[read()];
		tag[0]=tag[n+1]=1;
		re bool ia=1;ans=0;
		for(re int i=m;i;--i){
			if(tag[b[i]+1]&&tag[b[i]-1])ia=0;
			if(!(tag[b[i]+1]+tag[b[i]-1]))++ans;
			tag[b[i]]=1;
		}
		if(!ia)puts("0");
		else printf("%d\n",ksm(2,ans));
	}
}