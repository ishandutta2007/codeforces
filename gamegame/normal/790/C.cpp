#include<iostream>
using namespace std;
int n;
char a[76];
int dp[76][76][76][2];
int pv[76],pk[76],pn[76];
int vp[76],kp[76],np[76];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		pv[i]=pv[i-1],pk[i]=pk[i-1],pn[i]=pn[i-1];
		if(a[i]=='V'){
			pv[i]++;
			vp[pv[i]]=i;
		}
		else if(a[i]=='K'){
			pk[i]++;
			kp[pk[i]]=i;
		}
		else{
			pn[i]++;
			np[pn[i]]=i;
		}
	}
	for(int i=0; i<=n ;i++){
		for(int j=0; j<=n ;j++){
			for(int k=0; k<=n ;k++){
				dp[i][j][k][0]=dp[i][j][k][1]=1e9;
			}
		}
	}
	dp[0][0][0][0]=0;
	for(int i=0; i<n ;i++){
		for(int j=0; j<=i ;j++){
			for(int k=0; j+k<=i ;k++){
				for(int x=0; x<2 ;x++){
					int l=i-j-k;
					if(j>pv[n] || k>pk[n] || l>pn[n]) continue;
					if(j!=pv[n]){
						int cur=vp[j+1];
						dp[i+1][j+1][k][1]=min(dp[i+1][j+1][k][1],dp[i][j][k][x]+(cur-min(j,pv[cur])-min(k,pk[cur])-min(l,pn[cur])-1));
					}
					if(k!=pk[n] && x==0){
						int cur=kp[k+1];
						dp[i+1][j][k+1][0]=min(dp[i+1][j][k+1][0],dp[i][j][k][x]+(cur-min(j,pv[cur])-min(k,pk[cur])-min(l,pn[cur])-1));
					}
					if(l!=pn[n]){
						int cur=np[l+1];
						dp[i+1][j][k][0]=min(dp[i+1][j][k][0],dp[i][j][k][x]+(cur-min(j,pv[cur])-min(k,pk[cur])-min(l,pn[cur])-1));
					}
				}
			}
		}
	}
	cout << min(dp[n][pv[n]][pk[n]][0],dp[n][pv[n]][pk[n]][1]);
}