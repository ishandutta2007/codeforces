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
int n,a[N];vector<int>p,q;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)
		if(i==1||a[i]!=a[i-1])p.pb(a[i]);
		else if(i==2||a[i]!=a[i-2])q.pb(a[i]);
		else return printf("NO\n"),0;
	cout<<"YES\n"<<p.size()<<endl;
	for(auto i:p)printf("%d ",i);
	int m=q.size();
	printf("\n%d\n",m);
	dep(i,m-1,0)printf("%d ",q[i]);
}