#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int inf=1e9;
void sol(){
	int n;bool a=0,b=0,c=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x&1)a=1;else b=1;
		c^=x&1;
	}
	printf("%s\n",((a&&b)||c)?"YES":"NO");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}