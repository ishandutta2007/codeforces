#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const ll inf=1e18;
const int mo=998244353;
char s[N];
void sol(){int cnt=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n)if(s[i]=='0')++cnt;
	if(!cnt||cnt==n){
		printf("%s\n",s+1);return;
	}
	rep(i,1,n)printf("%s",s[1]=='0'?"01":"10");printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}