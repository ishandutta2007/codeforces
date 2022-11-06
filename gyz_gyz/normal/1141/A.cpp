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
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int x,y;
	scanf("%d%d",&y,&x);
	if(x%y)return printf("-1\n"),0;
	int ans=0;x/=y;
	while(!(x&1))x>>=1,++ans;
	while(!(x%3))x/=3,++ans;
	printf("%d\n",x>1?-1:ans);
}