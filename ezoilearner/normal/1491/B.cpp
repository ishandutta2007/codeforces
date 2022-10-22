#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int n,q;
#define Maxn 105
int a[Maxn];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);int u,v;rd(u);rd(v);
		rep(i,1,n)rd(a[i]);
		int d=0;
		rep(i,2,n)d=max(d,(int)abs(a[i]-a[i-1]));
		if(d>=2)puts("0");
		else if(d>=1)printf("%d\n",min(u,v));
		else printf("%d\n",v+min(u,v));
	}
	return 0;
}