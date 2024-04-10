#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pre(a) cout<<fixed;cout.precision(a)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int n;
int arr[2010];
vector<int> x;
int cnt[2010];
int cnt2[2010];

int main() {
	fast;
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> arr[i];
		x.eb(arr[i]);
	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	for(int i=0; i<n; i++) {
		arr[i] = lower_bound(x.begin(), x.end(), arr[i]) - x.begin();
	}

	int ans = 10000;

	for(int i=0; i<n; i++) {
		memset(cnt2, 0, sizeof(cnt2));
		for(int j=n-1; j>=i-1; j--) {
			ans = min(ans, j - i + 1);
			cnt2[arr[j]]++;
			if(cnt[arr[j]] + cnt2[arr[j]] > 1 || j < i) {
				//cout << i << " " << j << endl;
				break;
			}
		}

		cnt[arr[i]]++;
		if(cnt[arr[i]] > 1) break;
	}

	cout << ans;
}