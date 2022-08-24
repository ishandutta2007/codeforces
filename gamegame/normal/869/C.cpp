#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef long long ll;
int n,m,k;
ll ncr[5001][5001];
ll fact[5001];
ll mod(ll m){
	return m%998244353;
}
ll cnt(int a,int b){
	ll ans=0;
	for(int k=0; k<=min(a,b) ;k++){
		ans=mod(ans+mod(fact[k]*ncr[a][k])*ncr[b][k]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int a,b,c;
	ncr[1][0]=ncr[1][1]=1;
	fact[0]=1;
	fact[1]=1;
	for(int i=2; i<=5000 ;i++){
		fact[i]=mod(fact[i-1]*i);
		ncr[i][0]=1;
		for(int j=1; j<=i ;j++){
			ncr[i][j]=mod(ncr[i-1][j-1]+ncr[i-1][j]);
		}
	}
	cin >> a >> b >> c;
	cout << mod(cnt(a,b)*mod(cnt(b,c)*cnt(c,a))) << endl;
}