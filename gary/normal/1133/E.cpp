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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[5000+10][5000+10];
int n,k;
LL sum[5000+10];
int a[5000+10];
LL final=-INF;
int main(){
	scanf("%d %d",&n,&k);
	rb(i,1,n){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i]; 
	}
	sort(a+1,a+1+n);
	rb(i,1,n){
		int l=1;
		rl(j,i,1){
			if(a[i]-a[j]<=5) continue;
			else {
				l=j+1;
				break;
			}
		}
		rb(j,1,k){
			dp[i][j]=max(dp[l-1][j-1]+i-l+1,dp[i-1][j]);
			final=max(dp[i][j],final);
		}
		
	}
	printf("%I64d\n",final);
	return 0;
}