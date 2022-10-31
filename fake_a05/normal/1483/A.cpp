#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int>
#define ii pair<int, int>
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2e5 + 5, mod = 1e9 + 7;

int tc;
int N, M;
int sum[maxN];
vi av[maxN];
int ans[maxN];

bool cmp(int i, int j){
	return sum[i] < sum[j];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while(tc--){
		cin >> N >> M;
		loop(i, 1, N){
			sum[i] = 0;
		}
		loop(i, 1, M){
			av[i].clear();
		}
		loop(i, 1, M){
			int k;
			cin >> k;
			loop(j, 1, k){
				int t;
				cin >> t;
				av[i].eb(t);
				if(k == 1) {
					sum[t]++;
					ans[i] = t;
				}
			}
		}
		loop(i, 1, M){
			if(av[i].size() > 1){
				sort(all(av[i]), cmp);
				int t = av[i][0];
				sum[t]++;
				ans[i] = t;
			}
		}
		bool ok = 1;
		loop(i, 1, N){
			ok &= sum[i] <= (M + 1) / 2;
		}
		if(!ok) {
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			loop(i, 1, M){
				cout << ans[i] << sp;
			}
			cout << endl;
		}
	}
}