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
const int d[]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25},M=15;
const int N=100+5;
bool mark[N];
int f[N];
int F(int x){
	if(!x)return 0;
	else if(mark[x])return f[x];
	else{
		rep(i,0,M-1){
			if(d[i]>x)break;
			int t=f[x-d[i]];
			if(~t)f[x]=max(f[x],t+1);
		}
		mark[x]=1;
		if(!f[x])f[x]=-1;
		return f[x];
	}
}
void init() {
	rep(i,1,100)F(i);
}
int solve(int x){
	int t=x%4;
	if(!t)return x/4;
	else if(t==1){
		return (x-9)/4+1;
	}else if(t==2){
		return (x-6)/4+1;
	}else if(t==3){
		return (x-15)/4+2;
	}
}
int main(){
	init();
	int T=rd();
	while(T--){
		int x=rd();
		if(x<=100)printf("%d\n",f[x]);
		else{
			printf("%d\n",solve(x));
		} 
	}
}