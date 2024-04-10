#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;
const int MAX = 200005;

int n;
pair<int, int> x[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
	{
	if(a.se != b.se)
		return a.se < b.se;
	return a.fi < b.fi;
	}

ll ans = 0;

int dawaj(int y) {
	return Minus.order_of_key(y);
	}

int daj(int y) {
	return Plus.order_of_key(y);
	}

map <int, int> ILE;

int main()
	{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d%d", &x[i].fi, &x[i].se);
	
	sort (x+1, x+n+1, cmp);
	
	for(int i = n; 1 <= i;)
		{
		int j = i;
		Minus.insert(-x[i].fi);
		Plus.insert(x[i].fi);
		while(j - 1 >= 1 && x[i].se == x[j - 1].se)
			{
			--j;
			Minus.insert(-x[j].fi);
			Plus.insert(x[j].fi);
			}
		int LAST = 1e9 + 10;
		for(int r=i; r>=j; r--){
			int prawo = 1 + dawaj(-x[r].fi) - dawaj(-LAST) - (LAST != 1e9 + 10);
			int lewo = 1 + daj(x[r].fi);
			ans += (ll) lewo * prawo;
			LAST = x[r].fi;
		}
		i = j-1;
		}
	printf("%lld", ans);
	return 0;
	}