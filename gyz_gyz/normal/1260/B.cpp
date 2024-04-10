#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
bool sol(){int x,y;
	scanf("%d%d",&x,&y);
	return !((x+y)%3)&&x<=y*2&&y<=x*2;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"YES":"NO");
}