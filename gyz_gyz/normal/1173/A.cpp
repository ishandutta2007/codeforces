#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int main(){int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(!z&&x==y)printf("0");
	else if(x>y+z)printf("+");
	else if(y>x+z)printf("-");
	else printf("?");
}