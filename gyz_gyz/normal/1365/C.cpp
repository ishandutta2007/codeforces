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
int a[N],t[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		a[x]=i;
	}
	rep(i,1,n){int x;
		scanf("%d",&x);
		++t[(i+n-a[x])%n];
	}int ans=0;
	rep(i,0,n-1)ans=max(ans,t[i]);
	printf("%d\n",ans);
}