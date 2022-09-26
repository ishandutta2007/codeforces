#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 100010
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
int n,k,a[N],t[N];
ll ans;
priority_queue<pair<ll,int> > q;
inline ll calc(int x,int y){
	int f=x%y,g=y-f,s=x/y;
	return 1LL*s*s*g+1LL*(s+1)*(s+1)*f;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans+=1LL*a[i]*a[i];
		t[i]=2;
		int tmp=a[i]>>1;
		if(a[i]>1)q.push(make_pair(1LL*a[i]*a[i]-1LL*tmp*tmp-1LL*(a[i]-tmp)*(a[i]-tmp),i));
	}
	for(int i=n+1;i<=k;++i){
		auto [x,u]=q.top();
		q.pop();
		ans-=x;
		++t[u];
		if(a[u]>=t[u]){
			q.push(make_pair(calc(a[u],t[u]-1)-calc(a[u],t[u]),u));
		}
	}
	printf("%lld\n",ans);
	return 0;
}