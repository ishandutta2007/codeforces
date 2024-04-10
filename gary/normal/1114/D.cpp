#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
int n;
int a[5000+10]={INF}; 
int flag[5000+10];
mp fir_app[5000+10];
int dp[5000+10/*[l*/][5000+10/*r]*/][2/* color follow the (k==0)? "l":"r"*/];
int main(){
//	freopen("Flood.in","r",stdin);
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	int tot=0;
	rb(i,1,n){
		if(a[i]!=a[i-1]){
			flag[i]=++tot;
		}
		else{
			flag[i]=flag[i-1];
		}
	}
	rl(i,n,1){
		if(fir_app[flag[i]].SEC==0){
			fir_app[flag[i]].SEC=i;
		}
		else{
			continue;
		}
	}
	rb(i,1,n){
		if(fir_app[flag[i]].FIR==0){
			fir_app[flag[i]].FIR=i;
		}
		else{
			continue;
		}
	}
	rb(i,1,tot){
		dp[fir_app[i].FIR][fir_app[i].SEC][0]=dp[fir_app[i].FIR][fir_app[i].SEC][1]=0;
	}
	rl(i,n,1){
		rb(j,i+1,n){
			if(i>=j||flag[i]==flag[j]||fir_app[flag[i]].FIR!=i||fir_app[flag[j]].SEC!=j) continue;
			dp[i][j][0]=min(dp[fir_app[flag[i]].SEC+1][j][0]+(a[i]!=a[fir_app[flag[i]].SEC+1]),dp[fir_app[flag[i]].SEC+1][j][1]+(a[i]!=a[j]));
			dp[i][j][1]=min(dp[i][fir_app[flag[j]].FIR-1][0]+(a[i]!=a[j])  ,dp[i][fir_app[flag[j]].FIR-1][1]+(a[j]!=a[fir_app[flag[j]].FIR-1])  );
		}
	}
	cout<<min(dp[1][n][1],dp[1][n][0]);
	return 0;
}