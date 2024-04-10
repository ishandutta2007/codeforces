#include<cstdio>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
map<int,int>vis;
int n,a[300002];
long long sum;
int h[300002],nxt1[500002],val[500002],cnt,xr,mod,val1[500002],p[19]={228521,228523,228539,228559,228577,228581,228587,228593,228601,228611,228617,228619,228637,228647,228677,228707,228713,228731};
inline int insert(re int x,re int y){	int tmp=x%mod;	nxt1[++cnt]=h[tmp],h[tmp]=cnt,val[cnt]=y,val1[cnt]=x; return cnt;}
inline int ask(re int x){	int tmp=x%mod,p=h[tmp];	while(p){		if(val1[p]==x)return val[p];		p=nxt1[p];	}	return 0;}
inline int add(re int x){int tmp=x%mod,p=h[tmp];	while(p){		if(val1[p]==x){++val[p];return p;}		p=nxt1[p];	}	insert(x,1);return cnt;}
signed main(){
	n=read();srand(time(0));mod=p[rand()%18];
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=30;~i;--i){
		cnt=0;memset(h,0,sizeof(h));
		re long long ans1=0,ans2=0;
		if(i){
		for(re int j=n;j;--j){
			if(a[j]&(1<<i)){
				ans1+=ask(((a[j]^(1<<i))>>(i))<<(i));
				add(((a[j])>>(i))<<(i));
			}
			else{
				ans2+=ask(((a[j]^(1<<i))>>(i))<<(i));
				add(((a[j])>>(i))<<(i));
			}
		}
		}
		else{
			for(re int j=n;j;--j)if(a[j]&(1<<i))ans1+=ask(a[j]^1),add(a[j]);else ans2+=ask(a[j]^1),add(a[j]); 
		}
		if(ans1<=ans2)sum+=ans1;
		else sum+=ans2,xr^=(1<<i);
	}
	printf("%lld %d\n",sum,xr);
}