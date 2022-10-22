#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );



void Main(){
	int* t = new int; cin >> *t;
	while ((*t)--){
		int* n = new int; cin >> *n;
		//cout << "N = " << *n << endl << flush;
		int *i = new int, *j = new int;
		int* arr = new int[(*n)+1];
		for (*i = 1; *i <= *n; *i += 1){
			cin >> *(arr+*i);
			//cout << "A[i] = " << *i << ' ' << *(arr+*i) << endl;
		}
		int* ans = new int(0);
		for (*i = 1; *i <= *n; *i += 1){
			for (*j = 1; *j < *i; *j += 1){
				//cout << "A[i] = " << *i << ' ' << *(arr+*i) << " / ";
				//cout << "A[j] = " << *j << ' ' << *(arr+*j) << endl;
				if (*(arr+*j) >= *(arr+*i)){ *ans -=- 1; }
			}
		}
		cout << *ans << endl;
		//cout << flush;
		delete i; delete j;
		delete n; delete []arr; delete ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}