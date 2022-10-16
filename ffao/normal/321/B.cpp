#include <bits/stdc++.h>
using namespace std;

char kk[10];
int st;

multiset<int> ciel;
vector<int> defense;
vector<int> atk;
vector<int> cielv;
int sa, sc,n,m;

int main() {
	scanf("%d %d", &n, &m);

	for (int i= 0; i <n;i++) {
		scanf("%s %d", kk, &st);

		if (kk[0]=='A') atk.push_back(st);
		else defense.push_back(st+1);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &st);
		ciel.insert(st);
		cielv.push_back(st);
	}

	int ans = 0;
	multiset<int> tt = ciel;
	
	int dmg = 0;
	bool ok = true;

	for (int i = 0; i < defense.size(); i++) {
		int k = defense[i];
		auto it = tt.lower_bound(k);
		if (it == tt.end()) {ok = false; break;}
		tt.erase(it);
	}

	for (int i = 0; i < atk.size(); i++) {
		int k = atk[i];
		auto it = tt.lower_bound(k);
		if (it == tt.end()) {ok = false; break;}
		dmg += (*it - atk[i]);
		tt.erase(it);
	}

	for (int a : tt) dmg+=a;
	if (ok) ans = max(ans, dmg);
	
	sort(cielv.begin(),cielv.end());
	sort(atk.begin(),atk.end());

	dmg = 0;
	for (int i = 1; i <= atk.size() && i <= cielv.size(); i++) {
		ok = true;
		for (int j = 0; j < i; j++) if (atk[j] > cielv[(int)cielv.size()-j-1]) ok = false;
		sa += atk[i-1];
		sc += cielv[(int)cielv.size()-i];
		dmg = sc-sa;
		if (ok) ans = max(ans,dmg);
	}
	printf("%d\n",ans);
}