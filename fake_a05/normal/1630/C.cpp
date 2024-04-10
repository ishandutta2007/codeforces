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
int n; 
int arr[maxn]; 
int first[maxn], last[maxn]; 
#define fi first
#define se second
//1 2 4 4 3 1 2 3
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int tc = 1; 
	while(tc--) { 
		cin >> n; 
		fori(i,1 , n) { 
			first[i] = maxn - 1;
			last[i] = -1; 
		}
		fori(i, 1, n) { 
			cin >> arr[i];
			first[arr[i]] = min(first[arr[i]], i); 
			last[arr[i]] = max(last[arr[i]], i);  
		}
		vector<ii> segs; 
		fori(i, 1, n) { 
			if(first[i] < last[i]) segs.eb(first[i], last[i]); 
		}
		sort(begin(segs), end(segs)); 
		vector<ii> nw; int mx = -1, sum = 0; 
		for(auto t: segs) { 
			if(t.se < mx) continue; 
			else { 
				sum += t.se - max(mx, t.fi - 1); 
				mx = t.se; 
				nw.eb(t); 
			}
		}
		segs = nw; 
		int num = segs.size(); int seg_num = 0; 
		for(int i = 0; i < num; ) { 
			++seg_num; 
			if(i + 1 == num or segs[i + 1].fi > segs[i].se) { 
				++seg_num; 
				++i; 
			}
			else { 
				int j = i + 1; 
				while(j + 1 < num and segs[j + 1].fi < segs[i].se) ++j; 
				i = j; 
			}
		}
		cout << sum - seg_num << endl; 
	}
}