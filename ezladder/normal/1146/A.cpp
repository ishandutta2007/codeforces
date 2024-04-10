#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define y second

using namespace std;

string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> s;
	int cnt = 0;
	for (char c : s) if (c == 'a') cnt++;

	if (s.size() <= cnt * 2 - 1) cout << s.size();
	else cout << cnt * 2 - 1;
}