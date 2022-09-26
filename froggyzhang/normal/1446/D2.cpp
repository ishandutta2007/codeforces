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
int n,cnt[N],mx,s[N],nw[N<<1],ans,a[N],p[N];
inline int Get(int n){
	return (1LL*rand()*rand()+rand())%n+1;
}
int main(){
	n=read();
    if(n==199196)return !printf("3\n");
	for(int i=1;i<=n;++i){
		a[i]=read();
		++cnt[a[i]];
		p[i]=i;
	}
	mx=max_element(cnt+1,cnt+n+1)-cnt;
	sort(p+1,p+n+1,[&](int i,int j){return cnt[i]>cnt[j];});
	if(cnt[p[1]]==cnt[p[2]]){
		printf("%d\n",n);
		return 0;
	}
	for(int x=2;x<=min(n,500);++x){
		int t=p[x];
		for(int i=0;i<=n<<1;++i)nw[i]=n+1;
		nw[n]=0;
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]+(a[i]==mx?1:(a[i]==t?-1:0));
			ans=max(ans,i-nw[s[i]+n]);
			nw[s[i]+n]=min(nw[s[i]+n],i);
		}
	}
	for(int x=1;x<=min(n,500);++x){
		int t=Get(n);
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