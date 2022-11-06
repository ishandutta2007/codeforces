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
void sol(){
	scanf("%s",s+1);
	int n=strlen(s+1),ans=0,nw=0;
	dep(i,n,1){
		if(s[i]=='A'&&nw)--nw,ans+=2;
		if(s[i]=='B')++nw;
	}
	if(nw)ans+=nw/2*2;
	printf("%d\n",n-ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}