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
#define pre(a) //cout<<fixed; //cout.precision(a);
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll; 
typedef long double ld;
const long long INF = 1e18;  
const int inf = 1e9;

int n, m;
int a[2010];
int b[2010];
vector<pii> v;
vector<int> slc, sld;
vector<pii> upd;

int mx[2010];
priority_queue<int> pQ, del;

int right(int x, int y) {
	int t = upper_bound(all(sld), -y) - sld.begin() - 1;

	if(slc[t] + 1 <= x) return 0;
	return slc[t] + 1 - x;
}

int up(int x, int y) {
	int t = lower_bound(all(slc), x) - slc.begin();
	if(-sld[t] + 1 <= y) return 0;
	return -sld[t] + 1 - y;
}

int main() {
	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
	}

	for(int i=1; i<=m; i++) {
		int c, d;
		cin >> c >> d;
		v.eb(c, d);
	}

	sort(all(v));

	slc.eb(-inf);
	sld.eb(-inf);

	for(auto i : v) {
		while(sld.size() && -sld.back() <= i.se) slc.pop_back(), sld.pop_back();
		slc.eb(i.fi);
		sld.eb(-i.se);
	}

	slc.eb(inf);
	sld.eb(inf);

	ll sum = 0;

	for(int i=1; i<=n; i++) {
		mx[i] = up(a[i], b[i]);
		pQ.em(mx[i]);
		
		int t = lower_bound(all(slc), a[i]) - slc.begin();

		for(int j=t; j<slc.size()-1; j++) {
			int dx = slc[j] + 1 - a[i];
			upd.eb(dx, i);
			//cout << dx << " " << i << endl;
		}
	}
	//cout << endl;

	sort(all(upd));

	int ans = pQ.top();
	int pre = 0;

	for(int i=0; i < upd.size(); ) {
		int j = i;

		for(j; j < upd.size() && upd[j].fi == upd[i].fi; j++) {
			del.em(mx[upd[j].se]);
			
			mx[upd[j].se] = up(a[upd[j].se] + upd[j].fi, b[upd[j].se]);
			//cout << upd[j].fi << " " << upd[j].se << " " << mx[upd[j].se] << "\n";
			
			pQ.em(mx[upd[j].se]);
		}

		while(del.size() && del.top() == pQ.top()) del.pop(), pQ.pop();
		ans = min(ans, upd[i].fi + pQ.top());

		i = j;
	}

	cout << ans;
}