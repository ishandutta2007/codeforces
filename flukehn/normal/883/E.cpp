#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
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
const int N=55,M=1010;

int n, m;
char s[N], t[M][N];
int cnt[(1<<8)], Tim;
int tmp[(1<<8)];

bool check(char *t){
	memset(tmp,0,sizeof tmp);
	rep(i,0,n-1)if(s[i]!='*'&&s[i]!=t[i])return 0;
	rep(i,0,n-1)if(s[i]!='*')tmp[(int)s[i]] = 1;
	rep(i,0,n-1)if(s[i]=='*'&&tmp[(int)t[i]])return 0;
	return 1;
}

void mk(char *t) {
	memset(tmp,0,sizeof tmp);
	rep(i,0,n-1)if(s[i]=='*')tmp[(int)t[i]]=1;
	rep(i,0,(1<<8)-1)cnt[i]+=tmp[i];
}

int main() {
	n=rd(),scanf("%s%d",s,&m);
	rep(i,0,m-1)scanf("%s",t[i]);
	rep(i,0,m-1)if(check(t[i]))++Tim,mk(t[i]);
	int ans=0;
	rep(i,0,(1<<8)-1)
		if(cnt[i]==Tim)
			++ans;
	printf("%d\n",ans);
}