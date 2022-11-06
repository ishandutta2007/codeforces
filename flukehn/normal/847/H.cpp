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
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
int a[N],b[N],c[N];
ll f[N],g[N];
/*int calc(int i,int j){
	if(i>j)return 0;
	else return
}*/
int main(){
	int n=rd();
	rep(i,1,n)c[i]=a[i]=b[i]=rd();
	rep(i,2,n){
		f[i]=f[i-1];
		if(a[i]<=a[i-1]){
			f[i]+=a[i-1]+1-a[i];
			a[i] = a[i-1] + 1;
		}
	}
	per(i,n-1,1){
		g[i] = g[i+1];
		if(b[i]<=b[i+1]){
			g[i]+=b[i+1]+1-b[i];
			b[i] = b[i+1] + 1;
		}
	}
	ll mx=LONG_LONG_MAX;
	rep(i,1,n){
		mx=min(mx,f[i-1]+g[i+1]+max(a[i],b[i])-c[i]);
	}
	cout<<mx<<endl;
}