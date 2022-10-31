#include<bits/stdc++.h>

using namespace std;
#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); i ++)
#define ii pair<int, int>
#define vii vector<ii>

#define iii pair<int, ii>
#define viii vector<iii>

#define ld long double
#define li long long

#define eb emplace_back
#define vi vector<int>

#define int long long
#define sp ' '
#define endl '\n'
// 0 -> done != full -> 0 -> xor, no -> full -> xong
// full -> 2 -> dead, 4 -> dead, 6 -> x & x - 1, 1 , 0, 
//111, 110, 000, 001, 010, 101, 
signed main()
{
	int tc; cin >> tc; 
	while(tc--) {
		int n, k; 
		cin >> n >> k; 
		if(k == 0) { 
			fori(i, 0, n - 1) { 
				if(i < (n - 1 ^ i)) { 
					cout << i << sp << (n - 1 ^ i) << endl; 
				}
			}
		}
		else if(k < n - 1) { 
			cout << 0 << sp << (n - 1 ^ k) << endl; 
			cout << k << sp << n - 1 << endl; 
			fori(i, 0, n - 1) { 
				if(i and i != k and i != n - 1 and i != (n - 1 ^ k)) { 
					if(i < (n - 1 ^ i)) { 
						cout << i << sp << (n - 1 ^ i) << endl; 
					}
				}
			}
		}
		else { 
		 	if(n <= 4) { 
		 		cout << -1 << endl; 
			 }
			else { 
				cout << n - 1 << sp << (n - 1 ^ 1) << endl; 
				cout << 0 << sp << 2 << endl; 
				cout << 1 << sp << (n - 1 ^ 2) << endl; 
				fori(i, 0, n - 1) { 
					if(i and i != n - 1 and i != (n - 1 ^ 1) and i != 2 and i != 1 and i != (n - 1 ^ 2)) { 
						if(i < (n - 1 ^ i)) { 
							cout << i << sp << (n - 1 ^ i) << endl; 
						}
					}
				}
			}
		}
	}
}