#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
bool v[N];int c[N],a[N],p[N];
void sol(){int n,m=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		a[i]=p[x];
	}
	rep(i,1,n)if(!v[a[i]]){
		c[a[i]]=++m;v[a[i]]=1;
	}
	printf("%d\n",m);
	rep(i,1,n){
		printf("%d%c",c[a[i]],i==n?'\n':' ');
		v[a[i]]=0;
	}
}
int main(){int t;
	rep(i,2,1000)rep(j,2,i)if(!(i%j)){
		p[i]=j;break;
	}
	scanf("%d",&t);
	rep(i,1,t)sol();
}