#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
const char S[4]="RGB";bool v[4];int ans,a[4][4];string ns;
void dfs(int x,int y,string s){
	if(x>2){
		if(y>ans)ans=y,ns=s;return;
	}
	rep(i,0,2)if(!v[i]){
		v[i]=1;dfs(x+1,y+a[i][x],s+S[i]);v[i]=0;
	}
}
int main(){
	int n;string s;
	scanf("%d",&n);cin>>s;
	rep(i,0,n-1)if(s[i]=='R')++a[0][i%3];
	else if(s[i]=='G')++a[1][i%3];else ++a[2][i%3];
	dfs(0,0,"");printf("%d\n",n-ans);
	rep(i,0,n-1)printf("%c",ns[i%3]);
}