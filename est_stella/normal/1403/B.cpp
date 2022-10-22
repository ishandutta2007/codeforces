#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n, cnt;
int tree[30000010];
int l[30000010];
int r[30000010];
ll cal[111][2];

void update(int node, ll s, ll e, int i, int d) {
	tree[node]++;
	if(s == e) return;

	ll m = s + e >> 1;
	if(i <= m) {
		if(!l[node]) l[node] = cnt++;
		update(l[node], s, m, i, d-1);
		
		cal[d][0] += tree[r[node]];
	}
	else {
		if(!r[node]) r[node] = cnt++;
		update(r[node], m+1, e, i, d-1);
		
		cal[d][1] += tree[l[node]];
	}
}

int main() {
	fast;

	cin >> n;

	cnt += 2;

	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		update(1, 0, (1LL << 32) - 1, a, 31);
	}

	int x = 0;
	ll b = 0;
	for(int i=0; i<32; i++) {
		b += min(cal[i][0], cal[i][1]);
		if(cal[i][0] > cal[i][1]) {
			x |= (1LL << i);
		}
	}

	cout << b << " " << x;
}