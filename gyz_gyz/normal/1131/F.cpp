#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 2000010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int f[N],r[N],t[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)r[i]=f[i]=i;
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		x=gf(x);y=gf(y);
		t[r[x]]=y;r[x]=r[y];f[y]=x;
	}
	rep(i,1,n)if(gf(i)==i){
		for(;i;i=t[i])printf("%d ",i);
		return 0;
	}
}