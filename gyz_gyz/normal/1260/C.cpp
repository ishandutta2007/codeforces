#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
bool sol(){int x,y,k;
	scanf("%d%d%d",&x,&y,&k);
	if(x==y)return 1;
	int g=__gcd(x,y);x/=g;y/=g;
	if(x>y)swap(x,y);
	return (y-2)/x+1<k;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"OBEY":"REBEL");
}