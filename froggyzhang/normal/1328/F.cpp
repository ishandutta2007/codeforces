#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,k,a[N];
ll ans,pre[N],suf[N];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=n;i>=1;--i){
		suf[i]=suf[i+1]+a[i];
	}
	ans=pre[n];
	int nxt=1;
	for(int i=1;i<=n;i=nxt){
		while(a[i]==a[nxt])++nxt;
		int p=nxt-i;
		if(p>=k){
			ans=0;
			break;
		}
		ll l=1LL*(i-1)*a[i]-pre[i-1];
		ll r=suf[nxt]-1LL*(n-nxt+1)*a[i];
		if(nxt-1>=k){
			ans=min(ans,l-(nxt-1-k));
		}
		if(n-i+1>=k){
			ans=min(ans,r-(n-i+1-k));
		}
		ans=min(ans,l+r-n+k);
	}
	printf("%I64d\n",ans);
	return 0;
}