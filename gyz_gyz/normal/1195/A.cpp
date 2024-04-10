#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int a[N];
int main(){int ans=0,n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n){int x;
		scanf("%d",&x);++a[x];
	}
	rep(i,1,k)ans+=a[i]&1;
	printf("%d\n",n-ans/2);
}