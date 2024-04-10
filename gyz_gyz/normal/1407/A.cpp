#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=998244353;
void sol(){int n,t0=0,t1=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x)++t1;else ++t0;
	}
	if(t0>=t1){
		printf("%d\n",t0);
		rep(i,1,t0)printf("0%c",i==t0?'\n':' ');
	}else{
		if(t1&1)--t1;
		printf("%d\n",t1);
		rep(i,1,t1)printf("1%c",i==t1?'\n':' ');
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}