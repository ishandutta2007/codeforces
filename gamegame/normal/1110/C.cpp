#include<iostream>
using namespace std;
int a[26];
int n;
int lf(int x){
	for(int i=2; i*i<=x ;i++){
		if(x%i==0) return x/i;
	}
	return 1;
}
int solve(){
	cin >> n;
	for(int i=1; i<=25 ;i++){
		if((1<<i)-1==n) return a[i];
		if((1<<i)-1>n) return (1<<i)-1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=1; i<=25 ;i++){
		a[i]=lf((1<<i)-1);
	}
	int q;cin >> q;
	while(q--) cout << solve() << '\n';
}