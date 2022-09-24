#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[6005],y[6005],cntx[4][6005],cnty[4][6005],cntxy[4][6005];
ll ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=n;i>=1;i--){
		for(int j=0;j<3;j++)cntx[j][i]=cntx[j][i+1],cnty[j][i]=cnty[j][i+1],cntxy[j][i]=cntxy[j][i+1];
		cntx[x[i]&3][i]++,cnty[y[i]&3][i]++,cntxy[(x[i]+y[i])&3][i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((x[i]-x[j])%4==0&&(y[i]-y[j])%4==0)ans+=n-j;
			else if((x[i]-x[j])%4==0){//yi,j4 
				ans+=cntx[x[j]%4][j+1];
			}
			else if((y[i]-y[j])%4==0){
				ans+=cnty[y[j]%4][j+1];
			}
			else {
				ans+=cntxy[(x[j]+y[j])%4][j+1];
			}
		}
	}
	cout<<ans;
}