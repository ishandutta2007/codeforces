#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int bit, pri;
	string str;

	node() {}

	node(int bit, int pri, const string& str) : bit(bit), pri(pri), str(str) {}

	bool operator>(const node& x) const {
		if (str.length() != x.str.length())
			return str.length() > x.str.length();
		return str > x.str;
	}
};

priority_queue<node, vector<node>, greater<node> > q;
string ans[1 << 8][3];
bool vis[1 << 8][3];

bool cmp(const string& a, const string& b) {
	if (a.empty())
		return false;
	if (b.empty())
		return true;
	if (a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}

void tryp(int bit, int pri, const string& str) {
	if (ans[bit][pri].empty() || cmp(str, ans[bit][pri])) {
		ans[bit][pri] = str;
		q.push(node(bit, pri, str));
	}
}

string add_para(const string& s, int p1, int p2) {
	if (p1 > p2)
		return '(' + s + ')';
	return s;
}

int main() {
	q.push(node(0b00001111, 0, "x"));
	q.push(node(0b00110011, 0, "y"));
	q.push(node(0b01010101, 0, "z"));
	ans[0b00001111][0] = "x";
	ans[0b00110011][0] = "y";
	ans[0b01010101][0] = "z";
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		string str = tmp.str;
		if (vis[tmp.bit][tmp.pri])
			continue;
		vis[tmp.bit][tmp.pri] = true;
		tryp((~tmp.bit) & 255, 0, '!' + add_para(str, tmp.pri, 0));
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (!vis[i][j])
					continue;
				tryp(tmp.bit & i, 1, add_para(str, tmp.pri, 1) + '&' + add_para(ans[i][j], j, 1));
				tryp(tmp.bit | i, 2, str + '|' + ans[i][j]);
				tryp(tmp.bit & i, 1, add_para(ans[i][j], j, 1) + '&' + add_para(str, tmp.pri, 1));
				tryp(tmp.bit | i, 2, ans[i][j] + '|' + str);
			}
		}
	}
	int n;
	cin >> n;
	while (n--) {
		bitset<8> b;
		int a;
		cin >> b;
		a = b.to_ulong();
		cout << *min_element(ans[a], ans[a] + 3, cmp) << endl;
	}
	return 0;
}