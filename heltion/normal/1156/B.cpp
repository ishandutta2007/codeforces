//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 120;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	for(cin >> T; T; T -= 1){
		string s, so, se;
		cin >> s;
		for(char c : s) if(c & 1) so.push_back(c); else se.push_back(c);
		sort(so.begin(), so.end());
		sort(se.begin(), se.end());
		if(so.empty() or se.empty()) cout << (so + se) << endl;
		else{
			if(abs(*so.rbegin() - *se.begin()) != 1)  cout << (so + se) << endl;
			else if(abs(*so.begin() - *se.begin()) != 1){
				reverse(so.begin(), so.end());
				cout << (so + se) << endl;
			}
			else if(abs(*so.rbegin() - *se.rbegin()) != 1){
				reverse(se.begin(), se.end());
				cout << (so + se) << endl;
			}
			else if(abs(*se.rbegin() - *so.begin()) != 1)  cout << (se + so) << endl;
			else cout << "No answer" << endl;
		}
	}
	return 0;
}