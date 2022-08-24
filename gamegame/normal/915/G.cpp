#include<iostream>
using namespace std;
typedef long long ll;
const int N=2000000;
int n,k;
int m[2000001];
int pn[2000001];
bool sf[2000001];
ll dif[2000001];
ll b[2000001];
inline long long power(int x,int y,int z){//x^y%1e9+7
	long long int a[32];
	a[0]=x;
	for(int i=1; i<=31 ;i++){
		a[i]=a[i-1]*a[i-1]%z;
	}
	long long ans=1;
	for(int i=0; i<=31 ;i++){
		if(y&(1<<i)){
			ans=ans*a[i]%z;
		}
	}
	return ans;
}
const int MOD=1e9+7;
long long mod(long long m){
	return (m%MOD+MOD)%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=2; i<=2000 ;i++){
		for(int j=i*i; j<=N ;j+=i*i){
			sf[j]=true;
		}
	}
	cin >> n >> k;
	pn[1]=1;
	for(int i=2; i<=k ;i++){
		pn[i]=power(i,n,(int)1e9+7);
		if(sf[i]){
			m[i]=0;
			continue;
		}
		m[i]=1-m[i];
		for(int j=2*i; j<=k ;j+=i){
			m[j]+=m[i];
		}
	}
	for(int i=2; i<=k ;i++){
		if(m[i]==0) continue;
		for(int j=i; j<=k ;j+=i){
			dif[j]+=(pn[j/i]-pn[j/i-1])*m[i];
			dif[j]=mod(dif[j]);
		}
	}
	long long del=0;
	ll ans=0;
	for(int i=1; i<=k ;i++){
		del=mod(del+dif[i]);
		b[i]=mod(pn[i]-del);
		ans+=b[i]^i;
	}
	cout << mod(ans) << endl;
}