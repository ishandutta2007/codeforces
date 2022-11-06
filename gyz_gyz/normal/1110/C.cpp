#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 3000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int sol(int x){int s=1;
	rep(i,2,25){s=s*2+1;
		if(x==s)return a[i];
		if(x<s)return s;
	}return s;
}
int main(){
	int q;scanf("%d",&q);
	while(q--){int x;
		scanf("%d",&x);printf("%d\n",sol(x));
	}
}