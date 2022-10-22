#include<bits/stdc++.h>
using namespace std;

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
 
#define Maxn 5010

int n,k,inf,p[Maxn],q[Maxn],dp[Maxn][512],cnt[Maxn][Maxn];

void ckmin(int &x,int y){
	if(y<x)x=y;
}

int cost(int x,int S,int y){
	int ans=cnt[y][x];
	rep(i,1,k)
		if(S>>(i-1)&1)
			ans-=q[y]<q[x-i];
	return ans;
}

int main(){
	rd(n),rd(k);
	rep(i,1,n)rd(p[i]),q[p[i]]=i;
	memset(dp,0x3f,sizeof dp);
	rep(i,1,min(n,k+1))
		dp[i][(1<<i-1)-1]=0;
	rep(i,1,n)rep(j,1,n)
		cnt[i][j]=cnt[i][j-1]+(q[j]>q[i]);
	rep(i,1,n){
		per(mask,(1<<k)-1,0){
      		if(dp[i][mask]==0x3f3f3f3f)continue;
			rep(j,1,k)
				if(mask>>(j-1)&1)
					ckmin(dp[i][mask^(1<<j-1)],dp[i][mask]+cost(i,mask,i-j));
			rep(j,1,n-i){
				int new_mask=(mask<<j)+(1<<j-1)-1;
				if(new_mask>(1<<k))break;
				ckmin(dp[i+j][new_mask],dp[i][mask]+cost(i,mask,i+j));
			}
		}
	}
	return printf("%d\n",dp[n][0]),0;
}