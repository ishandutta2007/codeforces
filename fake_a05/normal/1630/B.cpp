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
const int maxn = 2e5 + 5; 
int n,k; 
int arr[maxn]; 
int temp_arr[maxn]; 
int last[maxn]; 

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int tc; cin >> tc; 
	while(tc--) { 
		cin >> n >> k; 
		fori(i, 1, n) { 
			cin >> arr[i]; 
			last[i] = 0; 
			temp_arr[i] = arr[i]; 
		}
		sort(temp_arr + 1, temp_arr + n + 1); //
		int num = (n + k + 1) / 2; // num - (n - num) >= k -> 2 * num >= n + k
		ii mn = ii(maxn - 1, maxn - 1); 
		fori(i, num, n) { 
			mn = min(mn, ii(temp_arr[i] - temp_arr[i - num + 1], temp_arr[i])); 
		}
		int min_range = mn.first, y = mn.second, x = y - min_range; 
		int pref = 0; 
		fori(i, 1, n) { 
			if(arr[i] >= x and arr[i] <= y) pref++; 
			else pref--; 
			if(pref > 0) last[pref] = i; 
		}
		cout << x << sp << y << endl; 
		fori(i, 1, k - 1) { 
			cout << last[i - 1] + 1 << sp << last[i] << endl; 
		}
		cout << last[k - 1] + 1 << sp << n << endl; 
	}
}