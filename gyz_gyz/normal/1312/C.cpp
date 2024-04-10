#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
const int mo=1e9+7;
int v[N];
bool cmp(int x,int y){return x>y;}
void sol(){int n;ll k;
	rep(i,0,64)v[i]=0;
	scanf("%d%lld",&n,&k);
	rep(i,1,n){ll x;int nw=0;
		scanf("%lld",&x);
		while(x){
			if(!(x%k))++nw,x/=k;
			else --x,++v[nw];
		}
	}
	rep(i,0,64)if(v[i]>1){
		printf("NO\n");return;
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}