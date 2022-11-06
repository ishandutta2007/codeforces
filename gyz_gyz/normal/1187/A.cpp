#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
void sol(){int n,s,t;
	scanf("%d%d%d",&n,&s,&t);
	int rs=s+t-n;
	printf("%d\n",max(0,max(s,t)-rs)+1);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}