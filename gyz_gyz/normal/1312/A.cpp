#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int inf=1e9;
const int mo=1e9+7;
void sol(){int x,y;
	scanf("%d%d",&x,&y);
	printf("%s\n",x%y?"NO":"YES");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}