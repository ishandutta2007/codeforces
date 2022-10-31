#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

bool primes[1111111];
int n;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	for (int i=2; i<1200; i++) for (int j=2*i; j<1111111; j+=i) primes[j]=true;
	primes[0]=primes[1]=true;
	cin >> n;
	for (int i=2; i<n; i++) {
		if (primes[n-i]&&primes[i]) {
			cout << i << ' ' << n-i << endl;
			return 0;
		}
	}
	return 0;
}