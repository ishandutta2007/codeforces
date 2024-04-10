#include<cstdio>
#include<string>
#include<queue>
using namespace std;
int mlen[3][256];
string sdp[3][256];
char tmp[20];
struct pqn {
	int val;
	int td;
	string s;
	bool operator<(const pqn&r)const {
		return s.size() > r.s.size() || (s.size() == r.s.size() && s > r.s);
	}
};
priority_queue<pqn> pq;
void spush(int val, int td, string s) {
	if (mlen[td][val] == 0 || (mlen[td][val] > s.size()) || (mlen[td][val] == s.size() && s < sdp[td][val])) {
		mlen[td][val] = s.size();
		sdp[td][val] = s;
		pqn x;
		x.val = val;
		x.td = td;
		x.s = s;
		pq.push(x);
	}
}
int main() {
	spush(0xf0, 0, "x");
	spush(0xcc, 0, "y");
	spush(0xaa, 0, "z");
	while (pq.size() > 0) {
		pqn x = pq.top();
		pq.pop();
		string s = x.s;
		int td = x.td;
		int val = x.val;
		if (s != sdp[td][val])continue;
		if (td == 0) {
			spush(255 - val, 0, "!" + s);
			spush(val, 1, s);
			for (int i = 0; i < 256; i++) {
				if (mlen[1][i] != 0) {
					spush(i&val, 1, sdp[1][i] + "&" + s);
				}
			}
		}
		else if (td == 1) {
			spush(val, 2, s);
			for (int i = 0; i < 256; i++) {
				if (mlen[0][i] != 0) {
					spush(i&val, 1, s + "&" + sdp[0][i]);
				}
			}
			for (int i = 0; i < 256; i++) {
				if (mlen[2][i] != 0) {
					spush(i | val, 2, sdp[2][i] + "|" + s);
				}
			}
		}
		else {
			spush(val, 0, "(" + s + ")");
			for (int i = 0; i < 256; i++) {
				if (mlen[1][i] != 0) {
					spush(i | val, 2, s + "|" + sdp[1][i]);
				}
			}
		}
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", tmp);
		int r = 0;
		for (int i = 0; i < 8; i++) {
			if (tmp[i] == '1')r += 1 << i;
		}
		printf("%s\n", sdp[2][r].c_str());
	}
	return 0;
}