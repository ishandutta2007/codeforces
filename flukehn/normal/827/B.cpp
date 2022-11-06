#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)/*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=2e5+11;
vector<int> v[N];
int main(){
	int n=rd(),k=rd(),tot=n-k;
	for(int i=0,j=2;j<=n-k;j++,i++,i%=k){
		v[i].pb(j);
	}
	rep(i,0,k-1)v[i].pb(n-k+i+1);
	printf("%d\n",v[0].size()+v[1].size());
	rep(i,0,k-1){
		printf("%d %d\n",1,v[i][0]);
		rep(j,1,v[i].size()-1){
			printf("%d %d\n",v[i][j-1],v[i][j]);
		}
	}
}