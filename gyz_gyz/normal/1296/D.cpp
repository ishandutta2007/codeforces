#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
int t[N];
int main(){int n,a,b,k;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	rep(i,1,n){int x;
		scanf("%d",&x);
		t[i]=(x-1)%(a+b)/a;
	}
	sort(t+1,t+n+1);
	rep(i,1,n){
		if(k<t[i])return printf("%d\n",i-1),0;
		k-=t[i];
	}
	printf("%d\n",n);
}