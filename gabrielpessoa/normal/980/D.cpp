#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 1e4+5;

int sieve[SIZE];
int primes[SIZE];
int arr[SIZE];
int qnt[SIZE];
map<int, int> existe;
int bu[SIZE];

int main(){
	int idx1 = 0;
	for(int i = 2; i < SIZE; i++) {
		if(sieve[i]) continue;
		primes[idx1++] = i;
		for(int j = i * i; j < SIZE; j += i) {
			sieve[j] = 1;
		}
	}
	//cout << "sieve feito com " << idx << '\n';
	int n;
	cin >> n;
	//n = 5000;
	int idx = 1;
	existe[0] = 0;
	//for(int i = 0; i < idx1; i++) cout << primes[i] << '\n';
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		//x = i;
		//cout << "DBG " << x << flush;
		if(!x) {
			arr[i] = 0;
			//cout << ' ' << 0 << '\n';
			continue;	
		}
		arr[i] = x/abs(x);
		x = abs(x);
		//cout << arr[i] << '\n';
		for(int j = 0; j < idx1 && primes[j] * primes[j] <= x; j++) {
			//cout << "counting " << primes[j] << endl;
			int count = 0;
			while(x % primes[j] == 0) {
				x /= primes[j];
				count++;
			}
			//cout << primes[j] << ' ' << count << '\n';
			//cout << "before is " << arr[i] << '\n';
			if(count & 1) arr[i] *= primes[j];
		}
		//cout << "Deb: " << arr[i] << ' ' << x << '\n';
		arr[i] *= x;
		if(existe.count(arr[i])) {
			arr[i] = existe[arr[i]];
		} else {
			arr[i] = existe[arr[i]] = idx++;
		}
		//cout << ' ' << arr[i] << endl;
		//cout << "processado " << arr[i] << endl;
	}
	//cout << endl;
	for(int i = 0; i < n; i++) {
		int q = 1;
		for(int j = 0; j < idx; j++) bu[j] = 0;
		bu[arr[i]]++;
		qnt[q]++;
		//int sozinhos = arr[i] != 0 ? 1 : 0;
		for(int j = i + 1; j < n; j++) {
			if(!bu[arr[j]]) {
				q++;
				//if(arr[j]) sozinhos++;
			} //else if(bu[arr[j] == 1] && arr[j]) sozinhos--;
			bu[arr[j]]++;
			if(bu[0] && q > 1) qnt[q - 1]++;
			else qnt[q]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << qnt[i] << ' ';
	}
	return 0;
}