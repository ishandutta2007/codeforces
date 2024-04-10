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
const int N=2000,M=111;
int n;
int f[M][N*2+11],g[M][N*2+11],T[M][N*2+11];
int sta[N],sop,dt[N];
bool cmp(int i,int j){
	return dt[i]<dt[j]; 
}
struct Node{
	int t,d,p,id;
	bool operator<(const Node&t)const{
		return d<t.d;
	}
	void read(){t=rd(),d=rd(),p=rd();}
} h[N];
int main(){
	n=rd();
	rep(i,1,n){
		h[i].read();
		h[i].id=i;
	}
	sort(h+1,h+n+1);
	rep(ttt,1,n){
		int t=h[ttt].t,d=h[ttt].d,p=h[ttt].p;
		dt[ttt]=d;
		rep(i,1,N)f[ttt][i]=f[ttt-1][i];
		per(i,d-t,1){
			if(f[ttt-1][i]+p>f[ttt][i+t]){
				f[ttt][i+t]=f[ttt-1][i]+p;
				g[ttt][i+t]=t;
				T[ttt][i+t]=1;
			}
		}
	}
	int mx=1;
	rep(i,2,N){
		if(f[n][i]>f[n][mx]){
			mx=i;
		}
	}
	cout<<f[n][mx]<<endl;
	per(i,n,1){
		if(T[i][mx]){
			sta[++sop]=h[i].id;
			mx-=g[i][mx];
		}
	}
	cout<<sop<<endl;
	per(i,sop,1)printf("%d%c",sta[i]," \n"[i==1]);
}