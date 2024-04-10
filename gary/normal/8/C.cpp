//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[16777216+10];
int las[16777216+10];
int xb,yb;
int n;//n<=24;
int x[25],y[25];
LL dis[25][25]; 
LL NO;
//return to the point '0' total minimal time 
void recover(int mask){
	if(mask==0) return;
	int LAS=las[mask];
	rb(i,1,n){
		if(!((LAS>>(i-1))&1)){
			if((mask>>(i-1))&1){
				printf("%d ",i);
			}
		}
	}
	printf("0 ");
	recover(las[mask]);
}
int main(){
	scanf("%d %d",&xb,&yb);
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d %d",&x[i],&y[i]);
	}
	x[0]=xb;
	y[0]=yb;
	rb(i,0,n)rb(j,0,n)dis[i][j]=(LL)(abs(x[i]-x[j]))*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]);
	int upp=1<<n;
	upp--;
	memset(dp,0x3f,sizeof(dp));
	NO=dp[0];
	dp[0]=(LL)(0);
	las[0]=INF;
	rb(mask,0,upp){
		if(dp[mask]<NO){
			rb(i,1,n){
				if(!(mask&(1<<(i-1)))){
					dp[mask|(1<<(i-1))]=min(dp[mask|(1<<(i-1))],dp[mask]+(dis[i][0]<<1));
					if(dp[mask|(1<<(i-1))]==dp[mask]+(dis[i][0]<<1)){
						las[mask|(1<<(i-1))]=mask;
					}
					int tmp_mask=mask|(1<<(i-1));
					rb(j,1,n){
						if(!(tmp_mask&(1<<(j-1)))){
							dp[tmp_mask|(1<<(j-1))]=min(dp[tmp_mask|(1<<(j-1))],dp[mask]+dis[i][0]+dis[i][j]+dis[j][0]);
							if(dp[tmp_mask|(1<<(j-1))]==dp[mask]+dis[i][0]+dis[i][j]+dis[j][0]){
								las[tmp_mask|(1<<(j-1))]=mask;
							}
						}
					}
					break;
				}
			}
		}
	}
	printf("%I64d\n",dp[upp]);
	printf("0 ");
	recover(upp);
	return 0;
}