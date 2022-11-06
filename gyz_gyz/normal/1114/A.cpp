#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 10010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int x1,y1,z1,x2,y2,z2;
	scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
	y1+=x1;z1+=y1;y2+=x2;z2+=y2;
	printf("%s\n",(x1>x2||y1>y2||z1>z2)?"NO":"YES");
}