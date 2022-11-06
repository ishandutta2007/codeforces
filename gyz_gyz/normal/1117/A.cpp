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
#define N 1010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int t,t1,t2,fl;bool opt,p0,p1,tg,tr;char c;string s;
int main(){int n,x,y;
	scanf("%d%d",&n,&x);
	int ans=1,mx=x,l=1;
	rep(i,2,n){y=x;
		scanf("%d",&x);
		if(x>mx)mx=x,l=ans=1;
		else if(x==mx){
			if(x==y){
				++l;if(l>ans)ans=l;
			}else l=1;
		}else l=0;
	}
	printf("%d\n",ans);
}