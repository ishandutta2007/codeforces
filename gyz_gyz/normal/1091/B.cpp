#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;pair<int,int>a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].fr,&a[i].sc);
	rep(i,1,n)scanf("%d%d",&b[i].fr,&b[i].sc);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	printf("%d %d\n",a[1].fr+b[n].fr,a[1].sc+b[n].sc);
}