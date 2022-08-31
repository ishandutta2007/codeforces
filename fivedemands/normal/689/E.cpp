#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
long long fact[200001];
pair<int,bool>a[400001];
long long mod(long long m){
	return m%(long long)(1e9+7);
}
inline long long power(long long x){//x^y%1e9+7
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
long long c(long long x,long long y){//x>=y
	return mod(mod(fact[x]*power(fact[x-y]))*power(fact[y]));
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	fact[0]=1;
	for(int i=1; i<=n ;i++){
		fact[i]=mod(fact[i-1]*i);
		cin >> a[i*2-1].first >> a[i*2].first;
		a[i*2].first++;
		a[i*2].second=true;
	}
	sort(a+1,a+2*n+1);
	long long ans=0;
	int cur=0;
	for(int i=1; i<=2*n ;i++){
		if(i!=1 && cur>=k) ans+=mod(a[i].first-a[i-1].first)*c(cur,k);
		ans=mod(ans);
		if(a[i].second) cur--;
		else cur++;
	}
	cout << ans << endl;
}