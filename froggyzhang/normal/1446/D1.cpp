#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,cnt[N],mx,s[N],nw[N<<1],ans,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		++cnt[a[i]];
	}
	mx=max_element(cnt+1,cnt+n+1)-cnt;
	for(int t=1;t<=100;++t){
		if(t==mx)continue;
		for(int i=0;i<=n<<1;++i)nw[i]=n+1;
		nw[n]=0;
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]+(a[i]==mx?1:(a[i]==t?-1:0));
			ans=max(ans,i-nw[s[i]+n]);
			nw[s[i]+n]=min(nw[s[i]+n],i);
		}
	}
	printf("%d\n",ans);
	return 0;
}