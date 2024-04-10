#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int A[Maxn],B[Maxn],fa[Maxn];

int getroot(int x){
	if(fa[x]!=x)fa[x]=getroot(fa[x]);
	return fa[x];
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(m);
		memset(A,0,sizeof(int)*(n+1));
		memset(B,0,sizeof(int)*(n+1));
		int x,y,ans=m;
		rep(i,1,n)fa[i]=i;
		rep(i,1,m){
			rd(x);rd(y);
			A[x]++;A[y]++;
			if(x==y)ans-=2;
			x=getroot(x);y=getroot(y);
			fa[x]=y;
		}
		rep(i,1,n)ans+=(getroot(i)==i);
		rep(i,1,n)
			if(!A[i])ans--;
		int t=0;
		rep(i,1,n)
			if(A[i]==1)t++;
		ans-=t/2;
		printf("%d\n",ans);
	}
	return 0;
}