#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
char s[N],t[N];
int main(){
	scanf("%s",s+1);scanf("%s",t+1);
	int n=strlen(s+1),m=strlen(t+1),nw=0,cg=0,ans=0;
	rep(i,1,m){
		if(s[i]!=t[i])nw^=1;
		if(s[i]!=s[i+1])cg^=1;
	}ans+=nw^1;
	rep(i,m+1,n){
		ans+=(nw^=cg)^1;
		cg^=(s[i-m]!=s[i-m+1])^(s[i]!=s[i+1]);
	}
	printf("%d\n",ans);
}