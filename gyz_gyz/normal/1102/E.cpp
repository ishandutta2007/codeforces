#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 1000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];map<int,int>v;set<int>s;
int main(){int n,ans=1,tot=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);++v[a[i]];
	}
	rep(i,1,n-1){
		if(!s.count(a[i])){
			s.insert(a[i]);++tot;
		}
		if(!--v[a[i]])--tot;
		if(!tot)add(ans,ans);
	}
	printf("%d\n",ans);
}