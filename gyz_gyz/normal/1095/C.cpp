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
int n,k;multiset<int>s;
int main(){
	scanf("%d%d",&n,&k);
	while(n){
		int x=n&(-n);
		s.insert(x);n-=x;--k;
	}
	if(k<0){printf("NO");return 0;}
	rep(i,1,k){
		auto t=--s.end();
		if(*t==1){printf("NO");return 0;}
		s.insert(*t/2);s.insert(*t/2);s.erase(t);
	}printf("YES\n");
	for(auto i:s)printf("%d ",i);
}