#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
int t[N],r[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		r[x]=t[x]?min(r[x],(y+n-x)%n):(y+n-x)%n;++t[x];
	}
	rep(i,1,n){int ans=0;
		rep(j,1,n)if(t[j]){
			ans=max(ans,(j+n-i)%n+(t[j]-1)*n+r[j]);
		}
		printf("%d ",ans);
	}
}