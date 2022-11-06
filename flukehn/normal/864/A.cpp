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
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int a[111];
int main(){
	int n=rd();
	set<int> S;
	rep(i,1,n){
		a[i]=rd();
		S.insert(a[i]);
	}
	if(S.size()==2){
		int x=*S.begin();
		int cnt=0;
		rep(i,1,n)if(a[i]==x){
			cnt++;
		}
		if(cnt==n/2){
			puts("Yes");
			set<int>::iterator b=S.begin();
			b++;
			printf("%d %d\n",x,*(b));
			return 0;
		}
	}
	puts("No");
}