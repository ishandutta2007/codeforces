#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <string>

using namespace std;


#define int long long
mt19937 rnd(rand());
int a[26], b[26];
string s, t;
int n, m;
int k = 0;


bool check(int mid){
	int ost = k;
	int nado[26];
	for (int i = 0; i < 26; ++i){
		nado[i] = a[i] * mid;
	}

	for (int i = 0; i < 26; ++i){
		if (b[i] < nado[i]){
			ost -= (nado[i] - b[i]);
		}
	}

	return ost >= 0;
}


signed main(){
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < n; ++i){
		a[i] = 0;
		b[i] = 0;
	}

	cin >> s;
	cin >> t;
	n = s.size(); 
	m = t.size();

	for (int i = 0; i < n; ++i){
		if (s[i] != '?'){
			++b[s[i] - 97];
		}

		k += (s[i] == '?');
	}

	for (int i = 0; i < m; ++i){
		++a[t[i] - 97];
	}

	int l = 0; 
	int r = 1000 * 1000 + 1;
	while (l < r - 1){
		int mid = (l + r) / 2;

		if (check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	int nado[26];
	for (int i = 0; i < 26; ++i){
		nado[i] = a[i] * l;
	}

	int mynado[26];
	for (int i = 0; i < 26; ++i){
		mynado[i] = 0;
		if (b[i] < nado[i]){
			mynado[i] = (nado[i] - b[i]);
		}
	}

	int myii = 0;
	for (int i = 0; i < n; ++i){
		if (s[i] != '?'){
			cout << s[i];
		}
		else{
			while (mynado[myii] <= 0 && myii < 25){
				++myii;
			}

			cout << char(myii + 97);
			--mynado[myii];
		}
	}
	
	return 0;
}