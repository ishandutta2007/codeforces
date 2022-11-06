#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
char s[N];
void sol(){int n,fl=0;
	scanf("%d%s",&n,s);
	rep(i,0,n-1){
		if(s[i]=='>')fl|=1;
		if(s[i]=='<')fl|=2;
	}
	if(fl<3){
		printf("%d\n",n);return;
	}int ans=0;
	rep(i,0,n-1)if(s[i]=='-'||s[(i+1)%n]=='-')++ans;
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}