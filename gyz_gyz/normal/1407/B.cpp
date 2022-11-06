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
int a[N];
void sol(){int n;
	scanf("%d",&n);int nw=0;
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){int x=0;
		rep(j,1,n)if(a[j]&&(!x||(i==1&&a[j]>a[x])||(i>1&&__gcd(nw,a[j])>__gcd(nw,a[x]))))x=j;
		printf("%d%c",a[x],i==n?'\n':' ');
		nw=__gcd(nw,a[x]);a[x]=0;
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}