#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=5011;
char s[N];
char f[N][N];
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif 
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		int cnt=0;
		rep(j,i,n){
			if(s[j]!=')')++cnt;else --cnt;
			if(cnt>=0)f[i][j]=1;
			else break;
		}
	}
	int ans=0;
	rep(i,1,n){
		int cnt=0;
		per(j,1,i){
			if(s[j]!='(')++cnt;else --cnt;
			if(cnt>=0)ans+=((i-j&1)&&f[j][i]);
			else break;
		}
	}
	cout<<ans<<endl;
}