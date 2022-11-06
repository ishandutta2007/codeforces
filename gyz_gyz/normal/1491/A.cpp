#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=1e9+7;
const ll inf=1e9;
int a[N];
int main(){int n,m,s=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i])++s;
	}
	rep(i,1,m){int op,x;
		scanf("%d%d",&op,&x);
		if(op==1){
			a[x]^=1;
			if(a[x])++s;else --s;
		}
		if(op==2)printf("%d\n",s>=x?1:0);
	}
}