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

long long n;
long long arr[200010];
long long ans[200010];
long long tree[200010];

void update(int i, long long x) {
	while(i <= n) {
		tree[i] += x;
		i += i & (-i);
	}
}

long long sum(int i) {
	i--;
	long long ret = 0;
	while(i) {
		ret += tree[i];
		i -= i & (-i);
	}

	return ret;
}

int main() {
	fast;

	cin >> n;

	for(long long i=0; i<n; i++) {
		cin >> arr[i];
		update(i+1, i+1);
	}

	for(int i = n-1; i>=0; i--) {
		long long l = 1, r = n;
		while(l != r) {

			long long mid = (l+r+1)/2;
			long long t = sum(mid);

			//cout << i << " " << l << " " << r << " " << t << endl;

			if(t > arr[i]) r = mid-1;
			else l = mid;
		}

		ans[i] = l;
		update(l, -l);

		//cout << arr[i] << " " << l << endl;
	}

	for(int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
}