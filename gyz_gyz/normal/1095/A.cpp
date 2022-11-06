#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 300000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
int n;char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);int x=0;
	rep(i,1,n){x+=i;
		if(x>n)break;
		printf("%c",s[x]);
	}
}