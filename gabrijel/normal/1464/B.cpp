#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, x, y;
	string s;
	cin >> s;
	cin >> x >> y;
	n = (int)s.size();
	vector <ll> up;
	ll br0 = 0, br1 = 0;
	ll rj = 0, mini, poc;
	REP(i, n) {
		if(s[i] == '0') {
			rj += br1 * y;
			br0++;
		}
		else if(s[i] == '1') {
			rj += br0 * x;
			br1++;
		}
		else {
			up.push_back(i);
			rj += br1 * y;
			br0++;
		}
	}
	mini = rj;
	poc = rj;
	ll lijevo0 = 0, desno0 = br0, lijevo1 = 0, desno1 = br1;
	REP(i, n) {
		if(s[i] == '0') {
			desno0--;
			lijevo0++;
		}
		else if(s[i] == '1') {
			desno1--;
			lijevo1++;
		}
		else {
			desno0--;
			rj -= lijevo1 * y;
			rj -= desno1 * x;
			rj += lijevo0 * x;
			rj += desno0 * y;
			lijevo1++;
		}
		mini = min(mini, rj);
	}
	//
	rj = poc;
	lijevo0 = br0, desno0 = 0, lijevo1 = br1, desno1 = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '0') {
			desno0++;
			lijevo0--;
		}
		else if(s[i] == '1') {
			desno1++;
			lijevo1--;
		}
		else {
			lijevo0--;
			rj -= lijevo1 * y;
			rj -= desno1 * x;
			rj += lijevo0 * x;
			rj += desno0 * y;
			desno1++;
		}
		mini = min(mini, rj);
	}
	//
	cout << mini << endl;
	return 0;
}