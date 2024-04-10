#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
int v[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n*2+1)v[i]=0;
	rep(i,1,n){int x;
		scanf("%d",&x);++v[x];
	}
	int ans=0;
	rep(i,1,2*n+1){
		if(v[i-1]>1){
			if(v[i])++v[i+1];
			v[i]=1;
		}
		if(v[i])++ans;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}