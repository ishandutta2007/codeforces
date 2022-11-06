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
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,x,y,t,w,mx,d[N];
int main(){
	scanf("%d",&n);scanf("%d",&x);mx=x;w=1;
	rep(i,2,n){y=x;
		scanf("%d",&x);mx=max(x,mx);
		if(x!=y){
			if(w){
				if(x>y){
					printf("NO\n");return 0;
				}else d[++t]=y;
			}else{
				if(t&&x>d[t]){
					printf("NO\n");return 0;
				}
				if(t&&d[t]==x)--t,w=0;else w=1;
			}
		}else w^=1;
	}if(w)d[++t]=x;
	if(t&&d[t]<mx)printf("NO\n");else printf("YES\n");
}