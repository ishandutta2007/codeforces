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
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
char a[N];
int main(){int n;bool fl=1;
	scanf("%s",a+1);
	for(n=1;a[n];)++n;--n;
	rep(i,1,n/2)if(a[i]!=a[1]||a[n+1-i]!=a[1]){fl=0;break;}
	if(fl){printf("Impossible");return 0;}
	rep(i,1,n/2)if(!(n%(i*2))){fl=1;
		rep(j,1,i)if(a[i+1-j]!=a[j])fl=0;
		if(fl)continue;fl=0;
		rep(j,1,i)if(a[i*2+1-j]!=a[j])fl=1;
		if(fl)continue;
		rep(j,i*2+1,n)if(a[j]!=a[(j-1)%(i*2)+1]){fl=1;break;}
		if(!fl)return printf("1\n"),0;
	}
	printf("2\n");
}