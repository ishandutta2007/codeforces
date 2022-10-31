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
const int maxn = 1e6 + 5, inf = LLONG_MAX / 10ll; 
#define fi first
#define se second
//1 2 4 4 3 1 2 3
// b1 = 1 -> done
// i & j -> j - i
// gcd of all
// g = 1 -> done
// g = 2 -> chon chan so
// 3 -> 111, 11011, 1101011, 1001 
/// 3 -> 1001, 10101, 
// tat ca modulo k phai cung tinh chan le ? 
int n, m; 
int arr[maxn]; 
vi A[maxn]; 
int sum[2]; 
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int tc = 1; cin >> tc; 
	while(tc--) { 
		cin >> n >> m; 
		fori(i, 0, n) A[i].clear(); 
		fori(i, 1, n) { 
			cin >> arr[i];
		}	
		sum[0] = sum[1] = 0; 
		int g = 0; 
		fori(i, 1, m) { 
			int v; cin >> v; 
			g = __gcd(g, v); 
		}
		fori(i, 1, n) { 
			A[i % g].eb(arr[i]); 	
		}
		int ans = 0; fori(i, 1, n) ans += arr[i]; 
		fori(odd, 0, 1) { 
			fori(rem, 0, g - 1) { 
				int pref_sum = 0, mn = inf; 
				sort(begin(A[rem]), end(A[rem])); 
				fori(i, 0, A[rem].size()) {
					if(i) pref_sum += A[rem][i - 1]; 
					if(i % 2 == odd) { 
						mn = min(mn, pref_sum); 
					}
				}
				sum[odd] += mn; 
			}
		}
		cout<< ans - 2 * min(sum[0], sum[1]) << endl; 
	}
}