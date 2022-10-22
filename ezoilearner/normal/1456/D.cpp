#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
#define Maxn 5005
#define cout cerr
#define FR first
#define SE second
int dp[Maxn][Maxn][2];
pii A[Maxn];

bool Judge(pii t1,pii t2){
	int l=t1.SE-(t2.FR-t1.FR),r=t1.SE+(t2.FR-t1.FR);
	if(l<=t2.SE&&t2.SE<=r)return true;
	return false;
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
	memset(dp,-1,sizeof(dp));
	rd(n);
	for(int i=1;i<=n;++i)rd(A[i].FR),rd(A[i].SE);
	dp[0][0][1]=0;
	ll h=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j){
			pii fr;
			if(dp[i][j][1]!=-1){
				int t=dp[i][j][1];
				fr=pii(t,A[j].SE);
				ll z=abs(fr.SE-A[i+1].SE)+(ll)fr.FR;
				if(z<=A[j+1].FR){
					int p=z;
					if(p<A[j].FR)p=A[j].FR;
					if(j<i){
						if(Judge(pii(p,A[i+1].SE),A[j+1]))dp[i+1][i+1][0]=0;
					}else{
						if(dp[i+1][i+1][1]==-1)dp[i+1][i+1][1]=p;
						else dp[i+1][i+1][1]=min(dp[i+1][i+1][1],p);
					}
				}
				if(j==i){
				 	int &tmp=dp[i+1][j][1];
					if(tmp==-1)tmp=dp[i][j][1];
					else tmp=min(tmp,dp[i][j][1]);
				}else if(Judge(A[i],A[i+1])){
					int &tmp=dp[i+1][j][1];
					if(tmp==-1)tmp=dp[i][j][1];
					else tmp=min(tmp,dp[i][j][1]);
				}
			}
			if(dp[i][j][0]!=-1){
				fr=A[j-1];
				ll z=max(fr.SE-A[i+1].SE,A[i+1].SE-fr.SE)+(ll)fr.FR;
				if(z<=A[j+1].FR){
					int p=z;
					if(p<A[j].FR)p=A[j].FR;
					if(j<i){
						if(Judge(pii(p,A[i+1].SE),A[j+1]))dp[i+1][i+1][0]=0;
					}else{
						if(dp[i+1][i+1][1]==-1)dp[i+1][i+1][1]=p;
						else dp[i+1][i+1][1]=min(dp[i+1][i+1][1],p);
					}
				}
				if(j==i)dp[i+1][j][0]=0;
				else if(Judge(A[i],A[i+1]))dp[i+1][j][0]=0;
			}
		}
	if(dp[n][n][0]!=-1||dp[n][n][1]!=-1){
		puts("YES");
		return 0;
	}
	int hhh=0;
	for(int i=0;i<n;++i){
		if(dp[n][i][0]!=-1){
			hhh++;
			if(Judge(A[i-1],A[i+1])){
				puts("YES");
				return 0;
			}
		}
		if(dp[n][i][1]!=-1){
			hhh++;
			if(Judge(pii(dp[n][i][1],A[i].SE),A[i+1])){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}