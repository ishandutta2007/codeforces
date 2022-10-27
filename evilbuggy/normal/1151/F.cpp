#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

struct Matrix{
	int sz;
	vector<vector<ll> > arr;

	Matrix(){

	}

	Matrix(int is){
		sz = is;
		arr = vector<vector<ll> >(sz + 1, vector<ll>(sz + 1, 0));
	}

	void unitize(){
		for(int i = 0; i <= sz; i++){
			for(int j = 0; j <= sz; j++){
				arr[i][j] = (i == j);
			}
		}
	}

	Matrix operator*(const Matrix &a){
		Matrix c(sz);
		for(int i = 0; i <= sz; i++){
			for(int j = 0; j <= sz; j++){
				for(int k = 0; k <= sz; k++){
					(c.arr[i][j] += arr[i][k]*a.arr[k][j]) %= mod;
				}
			}
		}
		return c;
	}

	Matrix operator+(const Matrix &a){
		Matrix c(sz);
		for(int i = 0; i <= sz; i++){
			for(int j = 0; j <= sz; j++){
				c.arr[i][j] = arr[i][j] + a.arr[i][j];
				if(c.arr[i][j] >= mod)c.arr[i][j] -= mod;
			}
		}
		return c;
	}

};

int a[105];

ll modPow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1)(ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}

Matrix powerup(Matrix a, ll b){
	Matrix ans(a.sz);
	ans.unitize();
	while(b){
		if(b&1)(ans = ans*a);
		(a = a*a);
		b >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;

	int m = n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		m -= a[i];
	}
	if(m == n || m == 0){
		cout<<1<<endl;
		return 0;
	}

	Matrix A(m);
	for(int i = 0; i <= m; i++){
		// First m: 'i' zeros, 'm-i' ones
		// Last n-m: 'm-i' zeros, 'n+i-2*m' ones
		ll tmp = m*(m-1)/2 + (n-m)*(n-m-1)/2 + i*(m-i) + (m-i)*(n+i-2*m);
		tmp *= modPow(n*(n-1)/2, mod - 2);
		tmp %= mod;
		A.arr[i][i] = tmp;
		if(i != m){
			A.arr[i][i+1] = (m-i)*(m-i)*modPow(n*(n-1)/2, mod - 2)%mod;
		}
		if(i != 0){
			A.arr[i][i-1] = i*(n+i-2*m)*modPow(n*(n-1)/2, mod - 2)%mod;
		}
	}

	Matrix B = powerup(A, k);
	int p = m;
	for(int i = 1; i <= m; i++){
		p -= a[i];
	}

	cout<<B.arr[p][m]<<endl;

	return 0;
}