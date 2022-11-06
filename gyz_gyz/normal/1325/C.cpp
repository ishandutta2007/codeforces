#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int x[N],y[N],s[N],d[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x[i],&y[i]);
		++d[x[i]];++d[y[i]];
	}int tot=0;
	rep(i,1,n-1)if(min(d[x[i]],d[y[i]])==1)s[i]=tot++;
	rep(i,1,n-1)if(min(d[x[i]],d[y[i]])!=1)s[i]=tot++;
	rep(i,1,n-1)printf("%d\n",s[i]);
}