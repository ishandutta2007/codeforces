#include<bits/stdc++.h>
#define re register
#define int long long 
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int p[64],n,m,a[100002],c[100002],cnt,k,ss[100002];
char b[100002];
inline int ins(re int x){
	re int xx=x,ia=0;
	for(re int i=60;i;--i){
		if(xx&(1ll<<i)){
			if(p[i])xx^=p[i];
			else {ia=1;break;}
		}
	}
	if(xx==1)ia=1;
	if(!ia){
		if(cnt&&(rand()&1)){
		k=ss[1ll*rand()*rand()%cnt+1];
		n=ss[1ll*rand()*rand()%cnt+1];
		}
		return 0;
	}
	for(re int i=60;i;--i){
		if(x&(1ll<<i)){
			if(p[i])a[++cnt]=x,b[cnt]='^',c[cnt]=p[i],x^=p[i],ss[cnt]=a[cnt]^c[cnt];
			else {p[i]=x;//k=min(k,p[i]+n);
			return 0;}
		}
	}
	if(x)return 1;
	else return 0;
}
signed main(){
	srand(time(0));
//	freopen("a.out","w",stdout);
		memset(p,0,sizeof(p));
	k=n=read();cnt=0;
	re int pos=0;
	re int tim=0;
	while(!ins(k)&&cnt<=100000){
		++tim;
		a[++cnt]=k,b[cnt]='+',c[cnt]=n,ss[cnt]=a[cnt]+c[cnt],k+=n;
	}
	printf("%lld\n",cnt);
	for(re int i=1;i<=cnt;++i)printf("%lld %c %lld\n",a[i],b[i],c[i]);
//	}
}