#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int n;
long long pa,pb,pc;
long long prob[1001][1001];
long long mod(long long x){
	return x%1000000007;
}
inline long long inv(long long x){//x^y%1e9+7
	long long int a[32];
	a[0]=x;
	for(int i=1; i<=31 ;i++){
		a[i]=mod(a[i-1]*a[i-1]);
	}
	long long ans=1;
	for(int i=0; i<=31 ;i++){
		if(1000000005&(1<<i)){
			ans=mod(ans*a[i]);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> pa >> pb;
	prob[1][0]=1;//can ignore prefix b
	pc=inv(pa+pb);
	ll ans=0;
	for(int i=1; i<n ;i++){
		for(int j=0; j<n ;j++){
			prob[i+1][j]=mod(prob[i+1][j]+mod(prob[i][j]*pa)*pc);
			if(j+i<n) prob[i][i+j]=mod(prob[i][i+j]+mod(mod(prob[i][j]*pb)*pc));
			else{
				ll cur=mod(mod(prob[i][j]*pb)*pc);
				ans=mod(ans+cur*(i+j));
			}
		}
	}
	for(int j=0; j<n ;j++){
		ll cur=mod(pa*inv(pb))+n+j;
		ans=mod(ans+cur*prob[n][j]);
	}
	cout << ans << endl;
}