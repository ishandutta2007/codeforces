#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
const int mo=998244353;
int a[N],t[N];
bool sol(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		t[a[i]]=i;
	}int x=1;
	while(x<=n){
		int i=t[x]+1;
		for(;i<=n&&a[i];++i)if(a[i]!=a[i-1]+1)return 0;
		rep(j,t[x],i-1)a[j]=0;
		x+=i-t[x];
	}
	return 1;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"Yes":"No");
}