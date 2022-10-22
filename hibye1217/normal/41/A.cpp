#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;



void Main(){
	string s1, s2; cin >> s1 >> s2;
	int l1 = s1.size(), l2 = s2.size();
	if (l1 != l2){ cout << "NO"; return; }
	for (int i = 0; i < l1; i++){
		if (s1[i] != s2[l2-1-i]){ cout << "NO"; return; }
	}
	cout << "YES";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}