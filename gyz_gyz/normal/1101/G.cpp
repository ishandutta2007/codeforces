#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[30];
int main(){int n;
	scanf("%d",&n);int ans=n,tot=0;
	rep(i,1,n){int x;
		scanf("%d",&x);tot^=x;
		dep(j,29,0)if(x>>j){
			if(a[j])x^=a[j];else{
				a[j]=x;break;
			}
		}
		if(!x)--ans;
	}
	printf("%d\n",tot?ans:-1);
}