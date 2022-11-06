#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
int a[99][99];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	int t1=0,t2=0;
	rep(i,1,n){bool fl=0;
		rep(j,1,m)if(a[i][j])fl=1;
		if(!fl)++t1;
	}
	rep(j,1,m){bool fl=0;
		rep(i,1,n)if(a[i][j])fl=1;
		if(!fl)++t2;
	}
	printf("%s\n",min(t1,t2)&1?"Ashish":"Vivek");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}