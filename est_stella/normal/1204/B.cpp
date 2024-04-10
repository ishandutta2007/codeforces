#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

long long n, l, r;

int main() {
	fast;

	cin >> n >> l >> r;

	cout << (1LL<<l) - 1 + (n - l) << " " << (1LL << r) - 1 + (n - r) * (1L<<(r-1));
}