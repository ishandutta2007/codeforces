#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 105
#define N 20

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll C(int n,int m) {
	if(n<m) return 0;
	ll x=1,y=1;
	FOR(i,1,m) {
		x=x*(n-i+1)%Mod;
		y=y*i%Mod;
	}
	return x*Fast(y,Mod-2)%Mod;
}

int dp[N][N];
int Tmp[N];
int Num[N];
int dfs(int pos,int cnt,bool limit) {
	if(!pos) return cnt==0;
	if(!limit && ~dp[pos][cnt]) return dp[pos][cnt];
	int tmp=0;
	FOR(i,0,limit?Num[pos]:9) {
		int f=(i==4)||(i==7);
		tmp+=dfs(pos-1,cnt-f,limit && (i==Num[pos]));
	}
	if(!limit) dp[pos][cnt]=tmp;
	return tmp;
}
ll sum[M][8];
int main() {
	memset(dp,-1,sizeof(dp));
	int m,top=0;
	scanf("%d",&m);
	for(;m;m/=10) Num[++top]=m%10;
	FOR(i,0,top) Tmp[i]=dfs(top,i,1);
//	cerr<<Tmp[1]<<endl;
	sum[0][0]=1;
	Tmp[0]--;
	ll res=0;
	FOR(i,0,top) {
		ll tot=0;
		FOR(j,0,i-1) tot=(tot+sum[j][6])%Mod;
		res=(res+Tmp[i]*tot)%Mod;
		DOR(s,6,0) {
			FOR(k,0,100) if(sum[k][s]) {
				DOR(j,6,1) {
					if(k+j*i<=100 && s+j<=6) {
//						if(i==0) cerr<<Tmp[i]<<endl;
//						cerr<<"----"<<endl;
						sum[k+j*i][s+j]=(sum[k+j*i][s+j]+sum[k][s]*C(Tmp[i],j))%Mod;
					}
				}
			}
		}
	}
//	cerr<<res<<endl;
	FOR(i,1,6) res=(res*i)%Mod;
//	cerr<<Tmp[2]<<endl;
	
	printf("%lld\n",res);
	return 0;
}