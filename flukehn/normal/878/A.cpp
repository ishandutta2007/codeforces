#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
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
int op[500005],ak_[500005][15],n;
int ret[15][3],wrk[15][5];
char s[15]; 
int main(){
	int n=rd();
	rep(i,1,n){
		scanf("%s",s+1);
		if(s[1]=='&') op[i]=1;
		else if(s[1]=='|') op[i]=2;
		else op[i]=3;
		int x=rd();
		rep(j,0,9){
			ak_[i][j]=x&1;
			x>>=1;
		}
	}
	rep(i,0,9)ret[i][1]=1;
	rep(i,0,9){
		rep(j,1,n){
			rep(k,0,1){
				if(op[j]==1)ret[i][k]=ret[i][k]&ak_[j][i];
				else if(op[j]==2)ret[i][k]=ret[i][k]|ak_[j][i];
				else ret[i][k]=ret[i][k]^ak_[j][i];
			}
		}
	}
	printf("3\n");
	rep(i,0,9){
		if(ret[i][0]==0&&ret[i][1]==0)continue;
		if(ret[i][0]==1&&ret[i][1]==1)wrk[i][1]=1,wrk[i][2]=1;
		else if(ret[i][0]==1&&ret[i][1]==0)wrk[i][1]=1,wrk[i][3]=1;
		else wrk[i][1]=1;
	}
	rep(i,1,3){
		int abc233=0;
		per(j,0,9)abc233=abc233*2+wrk[j][i];
		if(i==1) printf("& ");
		else if(i==2) printf("| ");
		else printf("^ ");
		printf("%d\n",abc233);
	}
}