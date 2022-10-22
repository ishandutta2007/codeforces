#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )



// #define DEBUG

pi2 nxt[100020];
pi2 rev[100020];

void Main(){
	int n, q; cin >> n >> q;
	int sqn = sqrt(n);
	for (int i = 1; i <= n; i++){
		cin >> nxt[i].fr;
		rev[ nxt[i].fr ].fr = i;
	}
	for (int i = 1; i <= n; i++){
		int ptr = i;
		for (int j = 1; j <= sqn; j++){ ptr = nxt[ptr].fr; }
		nxt[i].sc = ptr;
		rev[ nxt[i].sc ].sc = i;
	}
	while (q--){
		int m, a, b; cin >> m >> a >> b;
		if (m == 1){
			swap(nxt[a].fr, nxt[b].fr);
			int ast = rev[a].sc, bst = rev[b].sc;
			int aed = ast, bed = bst;
			for (int i = 1; i <= sqn; i++){
				aed = nxt[aed].fr; bed = nxt[bed].fr;
			}
			nxt[ast].sc = aed; nxt[bst].sc = bed;
			rev[aed].sc = ast; rev[bed].sc = bst;
			for (int i = 1; i <= sqn; i++){
				ast = nxt[ast].fr; bst = nxt[bst].fr;
				aed = nxt[aed].fr; bed = nxt[bed].fr;
				nxt[ast].sc = aed; nxt[bst].sc = bed;
				rev[aed].sc = ast; rev[bed].sc = bst;
			}
			ast = a; bst = b;
			aed = ast; bed = bst;
			for (int i = 1; i <= sqn; i++){
				aed = nxt[aed].fr; bed = nxt[bed].fr;
			}
			nxt[ast].sc = aed; nxt[bst].sc = bed;
			rev[aed].sc = ast; rev[bed].sc = bst;
			for (int i = 1; i <= sqn; i++){
				ast = nxt[ast].fr; bst = nxt[bst].fr;
				aed = nxt[aed].fr; bed = nxt[bed].fr;
				nxt[ast].sc = aed; nxt[bst].sc = bed;
				rev[aed].sc = ast; rev[bed].sc = bst;
			}
		}
		if (m == 2){
			while (b >= sqn){ a = nxt[a].sc; b -= sqn; }
			while (b >= 1){ a = nxt[a].fr; b -= 1; }
			cout << a << endl;
		}
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}