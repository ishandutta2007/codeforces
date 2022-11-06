#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
map<int,int>v[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n-1)rep(j,0,m-1){
		int x;scanf("%d",&x);
		if(x<=n*m&&(x-1)%m==j)++v[j][(i+n-(x-1)/m)%n];
	}int ans=0;
	rep(i,0,m-1){int res=n;
		for(auto&j:v[i])res=min(res,j.first+n-j.second);
		ans+=res;
	}
	printf("%d\n",ans);
}