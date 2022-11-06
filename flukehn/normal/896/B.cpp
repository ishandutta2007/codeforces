#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge*i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
int n,m,c,f[2011];
int main(){
	n=rd(),m=rd(),c=rd();
	int L=0,R;
	f[R=n+1]=inf;
	while(m--){
		int x=rd(),p;
		if(2*x<=c){
			if(x>=f[L])f[p=++L]=x;
			else per(i,0,L-1)if(x>=f[i]){f[p=i+1]=x;break;}
		}else{
			if(x<=f[R])f[p=--R]=x;
			else rep(i,R+1,n+1)if(x<=f[i]){f[p=i-1]=x;break;}
		}
		printf("%d\n",p),fflush(stdout);
		if(L==R-1)return 0;
	}
}