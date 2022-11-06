#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
int l[N],r[N];
int main(){int n;ll ans=0;
	scanf("%d",&n);l[0]=r[0]=1;
	rep(i,1,n*2){int x;
		scanf("%d",&x);
		if(!l[x])l[x]=i;
		else r[x]=i;
	}
	rep(i,1,n)ans+=abs(l[i]-l[i-1])+abs(r[i]-r[i-1]);
	printf("%lld\n",ans);
}