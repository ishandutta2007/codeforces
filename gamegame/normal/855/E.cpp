#include<iostream>
using namespace std;
typedef long long ll;
ll dp1[11][71][1024],dp2[11][71][1024];
int dig[71],dcnt;
ll cnt(int b,ll num){
	dcnt=0;
	while(num!=0){
		dcnt++;
		dig[dcnt]=num%b;
		num/=b;
	}
	ll ans=0;
	for(int i=1; i<dcnt ;i++){
		ans+=dp1[b][i][0];
	}
	int tmp=0;
	for(int i=dcnt; i>=1 ;i--){
		for(int j=(i==dcnt); j<dig[i] ;j++) ans+=dp2[b][i-1][tmp^(1<<j)];
		tmp^=(1<<dig[i]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=2; i<=10 ;i++) dp1[i][0][0]=dp2[i][0][0]=1;
	for(int i=1; i<=70 ;i++){
		for(int j=2; j<=10 ;j++){
			for(int k=0; k<(1<<j) ;k++){
				for(int l=1; l<j ;l++){
					dp1[j][i][k]+=dp2[j][i-1][k^(1<<l)];
				}
				for(int l=0; l<j ;l++){
					dp2[j][i][k]+=dp2[j][i-1][k^(1<<l)];
				}
			}
		}
	}
	int q;
	cin >> q;
	for(int i=1; i<=q ;i++){
		int b;
		ll l,r;
		cin >> b >> l >> r;
		cout << cnt(b,r+1)-cnt(b,l) << '\n';
	}
}