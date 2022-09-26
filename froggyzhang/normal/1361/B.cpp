#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1500100
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,p,a[N],ans,cnt[N],mx,qwq;
int bin[N<<3],tot;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read(),p=read();
		tot=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			bin[++tot]=a[i];
		}
		if(p==1){
			printf("%d\n",n&1);
			continue;
		}
		sort(a+1,a+n+1,greater<int>());
		ans=qpow(p,a[1]),mx=a[1],qwq=1,++cnt[a[1]];
		for(int i=2;i<=n;++i){
			if(!qwq){
				ans=(ans+qpow(p,a[i]))%mod;
				++cnt[a[i]];
				int now=a[i];
				int myh=-1;
				while(cnt[now]>=p){
					cnt[now]-=p;
					if(cnt[now]>0)myh=max(myh,now);
					++now;
					++cnt[now];
					bin[++tot]=now;
				}
				if(cnt[now]>0)myh=max(myh,now);
				if(mx==-1||cnt[mx]>=0){
					mx=myh,qwq^=1;
				}
			}
			else{
				ans=(ans-qpow(p,a[i])+mod)%mod;
				--cnt[a[i]];
				int now=a[i];
				int myh=-1;
				while(cnt[now]<=-p){
					cnt[now]+=p;
					if(cnt[now]<0)myh=max(myh,now);
					++now;
					--cnt[now];
					bin[++tot]=now;
				}
				if(cnt[now]<0)myh=max(myh,now);
				if(mx==-1||cnt[mx]<=0){
					mx=myh,qwq^=1;
				}
			}
		}
		for(int i=1;i<=tot;++i)cnt[bin[i]]=0;
		printf("%d\n",ans);
	}
	return 0;
}