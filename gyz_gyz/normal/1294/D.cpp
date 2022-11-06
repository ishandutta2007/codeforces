#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=4e5+10;
int v[N];
int main(){int n,m,ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);++v[x%m];
		while(v[ans%m]>ans/m)++ans;
		printf("%d\n",ans);
	}
}