#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

vector<vector<int> > multiply(vector<vector<int> > &a, vector<vector<int> > &b){
	int x = (int)a.size();
	vector<vector<int> > ret(x, vector<int>(x));
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < x; k++){
				ret[i][k] += a[i][j]*1LL*b[j][k]%mod;
				if(ret[i][k] >= mod)ret[i][k] -= mod;
			}
		}
	}
	return ret;
}

vector<vector<int> > power(vector<vector<int> > &a, int n){
	int x = (int)a.size();
	vector<vector<int> > ret(x, vector<int>(x));
	for(int i = 0; i < x; i++){
		ret[i][i] = 1;
	}
	while(n){
		if(n&1)ret = multiply(ret, a);
		a = multiply(a, a);
		n >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, b, k, x;
	cin >> n >> b >> k >> x;
	
	vector<int> frequency(10);
	vector<vector<int> > A(x, vector<int>(x));
	
	for(int i = 0; i < n; i++){
		int d;
		cin >> d;
		frequency[d]++;
	}
	for(int prev = 0; prev < x; prev++){
		for(int dig = 0; dig < 10; dig++){
			int cur = (10*prev + dig)%x;
			A[prev][cur] += frequency[dig];
		}
	}
	A = power(A, b);
	cout << A[0][k] << '\n';

	return 0;
}