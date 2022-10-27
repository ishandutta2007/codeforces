#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int maxn = 300005;

ll x[maxn], p[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>x[i];
	}

	for(int j = 0; j < m; j++){
		cin>>p[j];
	}

	ll g = 0;
	for(int i = 1; i < n; i++){
		g = __gcd(g, x[i] - x[i-1]);
	}
	for(int j = 0; j < m; j++){
		if(g%p[j] == 0){
			ll st = x[0]%p[j];
			if(st == 0)st += p[j];
			if(x[0] < st)continue;
			cout<<"YES"<<endl;
			cout<<st<<" "<<j+1<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}