#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
inline char getc(){
	char c;
	while((c=getchar())>'z'||c<'a');
	return c;
}
bool vis1[1561],vis2[1561];
int main(){
	char a=getc(),b=getc();
	int n=rd();
	rep(i,1,n){
		int c=getc(),d=getc();
		vis1[c]=1,vis2[d]=1;
		if(c==a&&b==d){
			puts("YES");
			return 0;
		}
		swap(c,d);
		if(c==a&&b==d){
			puts("YES");
			return 0;
		}
	}
	if(vis2[a]&&vis1[b]){
		puts("YES");
	}
	else puts("NO");
}