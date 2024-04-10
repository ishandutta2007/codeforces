#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 998244353;
const int N = 200005;
ll pw[N];

void pre(){
	pw[0] = 1;
	for(int i = 1; i < N; i++){
		pw[i] = (pw[i-1]*10)%mod;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int n;
	cin>>n;
	for(int r = 1; r <= n - 2; r++){
		ll ans = pw[n-r-1]*9*(20 + 9*(n-r-1));
		cout<<ans%mod<<" ";
	}
	if(n > 1){
		cout<<180<<" ";
	}
	cout<<10<<endl;

	return 0;
}