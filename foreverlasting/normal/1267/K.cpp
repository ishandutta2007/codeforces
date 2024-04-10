//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
typedef long long ll;
ll ch[25][25],res;int cnt[25],sum[25],a[25],T,len;ll n;
void init(){
	fp(i,0,19)cnt[i]=0;
	R int pos=2;
	len=0;
	while(n)++cnt[n%pos],n/=pos,++len,++pos;
}
inline ll calc(){
	sum[len+1]=0;
	fd(i,len,0)sum[i]=sum[i+1]+cnt[i];
	R ll res=1;
//	printf("%d\n",len);
//	fp(i,0,len)printf("%d%c",cnt[i]," \n"[i==len]);
	fd(i,len,1)if(cnt[i]){
		if(sum[i]>len-i)return 0;
		res*=(ch[len-i-1-sum[i+1]][cnt[i]]+ch[len-i-1-sum[i+1]][cnt[i]-1]);
//		printf("%d %d\n",len-i-1-sum[i+1],cnt[i]);
	}
//	printf("%lld\n",res);
	return res;
}
int main(){
//	freopen("testdata.in","r",stdin);
	fp(i,0,20){
		ch[i][0]=1;
		fp(j,1,i)ch[i][j]=ch[i-1][j]+ch[i-1][j-1];
	}
	for(scanf("%d",&T);T;--T){
		scanf("%lld",&n);
		init();
//		printf("%lld\n",len);
		res=0;
		fp(i,1,len)if(cnt[i])--cnt[i],res+=calc(),++cnt[i];
//		fp(i,0,len)printf("%d %d\n",i,cnt[i]);
		printf("%lld\n",res-1);
	}
	return 0;
}