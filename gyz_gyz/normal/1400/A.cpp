#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
char s[N];
void sol(){int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)printf("%c",s[i*2-1]);
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}