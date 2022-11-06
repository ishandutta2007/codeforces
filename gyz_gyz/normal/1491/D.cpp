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
bool sol(){int x,y;
	scanf("%d%d",&x,&y);
	int tx=0,ty=0;
	rep(i,0,29)if((x>>i)&1)++tx;
	rep(i,0,29)if((y>>i)&1)++ty;
	if(tx<ty)return 0;
	dep(i,29,0)if((y>>i)&1){
		if(x>y||!x)return 0;
		y^=1<<i;--ty;
		dep(j,i,0)if((x>>j)&1){
			x^=1<<j;
			if(--tx==ty)break;
		}
	}
	return 1;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"YES":"NO");
}