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
#define exe {puts("-1");return 0;}
const int N=111;
int vis[N],n,a[N];
int main(){
	n=rd();
	int m=rd(),x;
	scanf("%d",&x);
	rep(i,1,m-1){
		int y=rd();
		//if(x==y&&x!=n)exe
		if(a[x]){
			if((a[x]+x)%n==y%n)goto E;
			else exe
		}
		if(x<y)a[x]=y-x;
		else a[x]=n+y-x;
		if(vis[a[x]])exe
		else vis[a[x]]=1;
		E:x=y;
	}
	int now=1;
	rep(i,1,n) {
		if (!a[i]) {
			while(vis[now])now++;
			a[i] = now++;
		}
		printf("%d%c",a[i]," \n"[i==n]);	
	}
		
}