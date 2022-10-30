#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cstddef>

#define ll long long
#define INFi 1000000009
#define INFl 1000000000000000009
#define mp make_pair
#define pb push_back
#define sort stable_sort

using namespace std;



int main(){
	int n, m, a, b;
	cin >> n >> m>> a >> b;
	if (m * a <= b) cout << a * n;
	else {
		int ans = 0, done = 0;
		while (n - done - m >= 0){
			done += m;
			ans += b;
		}
		if (a * (n - done) < b) ans += a * (n - done);
		else ans += b;
		cout << ans;
	}
	
}