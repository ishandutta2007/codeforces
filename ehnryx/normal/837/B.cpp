#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of why_is_this_so_ugly:

map<char,int> ugly;
ugly.insert(pair<char,int>('R', 0));
ugly.insert(pair<char,int>('G', 1));
ugly.insert(pair<char,int>('B', 2));

bitset<3> used;
string s;
int n, m;
cin >> n >> m;
vector<string> flag(n);
for (int i = 0; i < n; i++)
	cin >> flag[i];

vector<int> width;
bool h, v;
h = v = true;
int colours;
// check horizontal
colours = 1;
used[ugly[flag[0][0]]] = true;
for (int i = 1; i < n; i++) {
	if (flag[i][0] != flag[i-1][0]) {
		colours++;
		width.push_back(i);
		used[ugly[flag[i][0]]] = true;
	}
}
if (colours != 3) {
	h = false;
	goto next;
}
if (!(width[1] == 2*width[0] && n == 3*width[0])) {
	h = false;
	goto next;
}
for (int j = 1; j < m; j++) {
	for (int i = 0; i < n; i++) {
		if (flag[i][j] != flag[i][j-1]) {
			h = false;
			goto next;
		}
	}
}
if (h == true)
	goto end;
next:
// check vertical
width.clear();
colours = 1;
used[ugly[flag[0][0]]] = true;
for (int j = 1; j < m; j++) {
	if (flag[0][j] != flag[0][j-1]) {
		colours++;
		width.push_back(j);
		used[ugly[flag[0][j]]] = true;
	}
}
if (colours != 3) {
	v = false;
	goto end;
}
if (!(width[1] == 2*width[0] && m == 3*width[0])) {
	v = false;
	goto end;
}
for (int i = 1; i < n; i++) {
	for (int j = 0; j < m; j++) {
		if (flag[i][j] != flag[i-1][j]) {
			v = false;
			goto end;
		}
	}
}
end:
if ((h || v) && (used[0] && used[1] && used[2])) cout << "YES" << endl;
else cout << "NO" << endl;

The End