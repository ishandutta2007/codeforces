#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=998244353;
int a[N],b[N];
void sol(){int n,m=0,mi=1e9;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		mi=min(mi,a[i]);
	}
	rep(i,1,n)if(!(a[i]%mi))b[++m]=a[i];
	sort(b+1,b+m+1);int x=1;
	rep(i,1,n)if(!(a[i]%mi))a[i]=b[x++];
	rep(i,2,n)if(a[i]<a[i-1]){
		printf("NO\n");return;
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}