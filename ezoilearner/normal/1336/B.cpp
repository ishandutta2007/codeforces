#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

int n[3];
#define Maxn 100010
int a[3][Maxn];

ll D(int x){return 1ll*x*x;}

int main(){
	int T;
	rd(T);
	while(T--){
		ll Ans=5e18;
		rep(i,0,2)rd(n[i]);
		rep(i,0,2)
			rep(j,1,n[i])rd(a[i][j]);
		rep(i,0,2)sort(a[i]+1,a[i]+n[i]+1);
		rep(p,0,2)
			rep(q,0,2)
				if(q!=p)
					rep(r,0,2)
						if(r!=p&&r!=q){
							rep(i,1,n[p]){
								int t=a[p][i];
								int c=lower_bound(a[q]+1,a[q]+n[q]+1,t)-a[q];
								int d=upper_bound(a[r]+1,a[r]+n[r]+1,t)-a[r]-1;
								if(d>=1&&c<=n[q]){
									Ans=min(Ans,D(a[q][c]-t)+D(t-a[r][d])+D(a[q][c]-a[r][d]));
								}
							}
						}
		printf("%lld\n",Ans);
	}
	return 0;
}