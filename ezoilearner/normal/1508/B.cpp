#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

const ll inf=2000000000000000000ll;
int n;ll K;
#define Maxn 100010
int ans[Maxn]; 
ll h[Maxn];

int main(){
	int T;scanf("%d",&T);
	h[0]=1;
	h[1]=1;
	rep(i,2,100000)h[i]=min(h[i-1]*2,inf);
	while(T--){
		scanf("%d%lld",&n,&K);
		if(h[n]<K)puts("-1");
		else{
			int cnt=0;
			int l=1;
			while(l<=n){
				int t=n-l;
				while(h[t]<K){
					K-=h[t];t--;
				}
				per(i,n-t,l)ans[++cnt]=i;
				l=n-t+1;
			}
			rep(i,1,n)printf("%d ",ans[i]);puts("");
		}
	}
	return 0;
}