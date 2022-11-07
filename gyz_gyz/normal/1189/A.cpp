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
const int N=2e5+10;
const int mo=998244353;
char s[N];
int main(){int n,t=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='1')++t;else --t;
	if(t)printf("1\n%s\n",s+1);else printf("2\n%c %s\n",s[1],s+2);
}