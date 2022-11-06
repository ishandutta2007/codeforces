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
void sol(){
	scanf("%s",s+1);
	int n=strlen(s+1),ls=0,ans=0;
	rep(i,1,n)if(s[i]=='R'){
		ans=max(ans,i-ls);
		ls=i;
	}
	ans=max(ans,n+1-ls);
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}