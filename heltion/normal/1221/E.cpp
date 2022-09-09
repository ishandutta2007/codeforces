//Author: Heltion
//Date: 09-19-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		vector<int> v;
		int cnt = 0;
		for(char c : s)
			if(c == '.') cnt += 1;
			else{
				if(cnt) v.push_back(cnt);
				cnt = 0;
			}
		if(cnt) v.push_back(cnt);
		if(a >= 2 * b){
			int c[2] = {0, 0};
			int ma = 0;
			for(int x : v){
				if(x >= a) c[1] += 1;
				if(x >= b) c[0] += 1;
				ma = max(ma, x);
			}
			if(c[1] == 1 and c[0] == 1 and ma <= a + b - 1 + b - 1)
				cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		else{
			int c[3] = {0, 0, 0};
			int ma = 0;
			for(int x : v){
				ma = max(ma, x);
				if(x >= b and x < a) c[0] += 1;
				if(x >= a and x < 2 * b) c[1] += 1;
				if(x >= 2 * b) c[2] += 1;
			}
			if(c[0]){
				cout << "NO\n";
				continue;
			}
			if(c[2] >= 2){
				cout << "NO\n";
				continue;
			}
			if(not c[2]){
				if(c[1] & 1) cout <<"YES\n";
				else cout << "NO\n";
				continue;
			}
			bool ok = false;
			for(int i = 0; i <= ma - a; i += 1){
				int x = i, y = ma - a - i;
				int tc[2] = {c[1], 0};
				if(x >= b and x < a) continue;
				if(x >= a and x < 2 * b) tc[0] += 1;
				if(x >= 2 * b) tc[1] += 1;
				if(y >= b and y < a) continue;
				if(y >= a and y < 2 * b) tc[0] += 1;
				if(y >= 2 * b) tc[1] += 1;
				if(tc[1]) continue;
				if(tc[0] % 2 == 0) ok = true;
			}
			if(ok) cout <<"YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}