#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
int n,x,ans,a[N];char s[N];bool f[N],fl;
int main(){
	scanf("%d",&n);scanf("%s",s+1);x=0;fl=1;f[0]=1;
	rep(i,1,n){
		if(s[i]=='(')++x;else --x;
		if(x<0)fl=0;a[i]=x;f[i]=fl;
	}x=0;
	dep(i,n,1){
		if(x>0)break;
		if(f[i-1]&&!(a[i-1]+x+(s[i]==')')-(s[i]=='(')))++ans;
		if(s[i]=='(')++x;else --x;
	}
	printf("%d\n",ans);
}