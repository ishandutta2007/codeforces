#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,c,q;
#define Maxn 30005
#define cout cerr
#define FR first
#define SE second
int p[Maxn];

struct Data{
	pii to[5];int l;
	ll way,val;
}dp[Maxn][5];
ll sum[Maxn][5];
bool cmp(pii t1,pii t2){return p[t1.FR]<p[t2.FR];}

void init(int t){
	rep(i,1,n)sum[i][t]=sum[i-1][t]+dp[i-1][t].way;
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

inline void rd(ll &x){
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
		rd(n);rd(c);rd(q);
		rep(i,1,n)rd(p[i]);
		per(i,n,0)
			rep(j,0,c){
				dp[i][j].l=0;
				int &t=dp[i][j].l;
				rep(k,j,c)
					if(i+1+k-j<=n)dp[i][j].to[t++]=pii(i+1+k-j,k);
				sort(dp[i][j].to,dp[i][j].to+t,cmp);
				bool flag=true;
				dp[i][j].val=dp[i][j].way=0ll;
				for(int k=0;k<t;++k){
					pii cur=dp[i][j].to[k];
					if(cur.FR==i+1)flag=false;
					if(flag)dp[i][j].way+=dp[cur.FR][cur.SE].val;
					dp[i][j].val+=dp[cur.FR][cur.SE].val;
				}
				if(i==n)dp[n][j].val=1ll;
			}
		rep(i,0,c)init(i);
		int x;ll y;
		while(q--){
			rd(x);rd(y);
			int pos=0,at=0;
			if(y>dp[0][0].val)puts("-1");
			else{
			while(pos<x){
				int l=pos,r=n;
				while(l<r){
					int mid=(l+r)>>1;
					if(y>sum[mid+1][at]-sum[pos][at]&&y<=sum[mid+1][at]-sum[pos][at]+dp[mid+1][at].val)l=mid+1;
					else r=mid;
				}
				y-=sum[r][at]-sum[pos][at];
				if(x<=r){printf("%d\n",p[x]);break;}
				
				rep(j,0,dp[r][at].l-1){
					pii cur=dp[r][at].to[j];
					if(y<=dp[cur.FR][cur.SE].val){
						if(x<=cur.FR){
							printf("%d\n",p[r+1+cur.FR-x]);
							pos=n;
							break;
						}
						pos=cur.FR;at=cur.SE;
						break;
					}
					y-=dp[cur.FR][cur.SE].val;
				}
			}
		}
	}
	}
	return 0;
}