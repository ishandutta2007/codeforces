#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int LIM = 100000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll k = 1;
		for(; k < LIM; k++){
			if(k*(k+1)/2 > n)break;
		}
		k--;
		int rem = n - k*(k + 1)/2;
		if(rem == 0){
			cout<<13;
			while(k--)cout<<3;
			cout<<7<<endl;
		}else{
			cout<<133;
			while(rem--)cout<<7;
			k--; while(k--)cout<<3;
			cout<<7<<endl;
		}
	}

	return 0;
}