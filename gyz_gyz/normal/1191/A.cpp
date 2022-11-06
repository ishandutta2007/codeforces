#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int main(){int n;
	scanf("%d",&n);
	if(n%4!=2)printf("%d A\n",((n-2)/4+1)*4-n+1);
	else printf("1 B\n");
}