#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
int main(){int n,m;
	scanf("%d%d",&n,&m);
	int tot=0;
	rep(i,1,n){
		tot+=(i-1)/2;
		if(tot>=m){
			int x=i;
			if(!(x&1))++x;
			x+=(tot-m)*2;
			rep(j,1,i-1)printf("%d ",j);
			printf("%d ",x);
			rep(j,1,n-i)printf("%d ",100000000+j*10000);
			return 0;
		}
	}
	printf("-1\n");
}