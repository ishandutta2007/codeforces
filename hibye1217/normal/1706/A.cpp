#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;



void Main(){
	int t; cin >> t; while (t--){
		int n, m; cin >> n >> m;
		string s = "";
		for (int i = 1; i <= m; i++){ s += "B"; }
		while (n--){
			int p; cin >> p;
			int p1 = p-1, p2 = m-p;
			if (p1 > p2){ swap(p1, p2); }
			if (s[p1] != 'A'){ s[p1] = 'A'; } else{ s[p2] = 'A'; }
		}
		cout << s << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}