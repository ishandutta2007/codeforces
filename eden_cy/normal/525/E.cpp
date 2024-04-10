#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

const int M=(int)16e5;

int P[14],sz[M];

int n,K;

ll S,A[27],A1[27];

map<ll,int>mp[2][30];

map<ll,int>::iterator it,it1;
ll dp[M];

void solve(int L,int R,int p){
	int len=R-L+1;
	FOR(i,0,P[len]-1) {
		dp[i]=0;
		FOR(j,0,len-1) {
			int p1=i/P[j]%3;
			if(p1==1) {
				dp[i]+=A[L+j];
			}
			if(p1==2) {
				dp[i]+=A1[L+j];
			}
		}
	}
	FOR(i,0,P[len]-1) {
		if(dp[i]>=0&&dp[i]<=S&&sz[i]<=K) {
			mp[p][sz[i]][dp[i]]++;
		}
	}
}
int main(){
	P[0]=1;
	FOR(i,1,13) P[i]=P[i-1]*3;
	FOR(i,0,P[13]-1) {
		FOR(j,0,12) {
			int p=i/P[j]%3;
			if(p==2)sz[i]++;
		}
	}
	scanf("%d%d%lld",&n,&K,&S);
	FOR(i,1,n) {
		scanf("%lld",&A[i]);
		A1[i]=1;
		FOR(j,2,A[i]) {
			A1[i]=A1[i]*j;
			if(A1[i]>S)break;
		}
		if(A1[i]>S)A1[i]=S+1;
	}
	solve(1,n/2,0);
	solve(n/2+1,n,1);
	ll ans=0;
	FOR(i,0,K) {
		for(it=mp[0][i].begin(); it!=mp[0][i].end(); it++){
			ll a=(*it).first;
			int b=(*it).second;
			ll ned=S-a;
			for(int j=0;i+j<=K;j++){
				it1=mp[1][j].find(ned);
				if(it1!=mp[1][j].end()){
					int c=(*it1).second;
					ans+=(ll)b*c;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}