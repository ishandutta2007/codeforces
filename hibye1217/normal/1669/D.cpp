#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;

void Main(){
	int t; cin >> t;
	while (t--){
		int sl; string s; cin >> sl >> s;
		bool flg = 1;
		int st = 0; while (st < sl){
			if (s[st] == 'W'){ st += 1; continue; }
			int ed = st;
			while (ed < sl){
				if (s[ed] != 'W'){ ed += 1; }
				else{ break; }
			}
			bool c1 = 0, c2 = 0;
			for (int i = st; i < ed; i++){
				if (s[i] == 'R'){ c1 = 1; }
				if (s[i] == 'B'){ c2 = 1; }
			}
			flg &= (c1 && c2);
			st = ed;
		}
		if (flg){ cout << "Yes" << endl; } else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}