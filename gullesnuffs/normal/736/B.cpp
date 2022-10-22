#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int maxDiv(int x){
	for(int i=2; i*i <= x; ++i){
		if(x%i == 0)
			return (x/i);
	}
	return 1;
}

int solve(int n){
	int ret=maxDiv(n);
	rep(i,2,n-1){
		ret=min(ret, maxDiv(i)+solve(n-i));
	}
}

bool isPrime(int x){
	for(int i=2; i*i <= x; ++i){
		if(x%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	cin >> n;
	if(isPrime(n))
		cout << "1" << endl;
	else if(n%2 == 0)
		cout << "2" << endl;
	else if(isPrime(n-2))
		cout << "2" << endl;
	else
		cout << "3" << endl;
}