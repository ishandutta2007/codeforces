#include <bits\stdc++.h>
using std::cin;
using std::string;
string r1, r2, w, b;

bool insight_rook(string r, string w, string b) {
	if(r[0] == b[0] && !(w[0] == r[0] && ((r[1] < w[1] && w[1] < b[1]) || (r[1] > w[1] && w[1] > b[1]))))
		return true;
	if(r[1] == b[1] && !(w[1] == r[1] && ((r[0] < w[0] && w[0] < b[0]) || (r[0] > w[0] && w[0] > b[0]))))
		return true;
	return false;
}

int abs(int x) {
	return x < 0 ? -x : x;
}

bool insight_king(string w, string b) {
	return std::max(abs(w[0] - b[0]), abs(w[1] - b[1])) == 1;
}

bool insight(string r1, string r2, string w, string b) {
	if(b == w) w[0] = '1' + 20, w[1] = 'a' + 20;
	if(b == r1) r1[0] = '1' + 20, r1[1] = 'a' + 20;
	if(b == r2) r2[0] = '1' + 20, r2[1] = 'a' + 20;
	return insight_king(w, b) || insight_rook(r1, w, b) || insight_rook(r2, w, b);
}

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check() {
	if(!insight(r1, r2, w, b)) return false;
	for(int i = 0; i < 8; ++i) {
		string bb = b;
		bb[0] += dx[i]; bb[1] += dy[i];
		if('a' <= bb[0] && bb[0] <= 'h' && '1' <= bb[1] && bb[1] <= '8')
			if(!insight(r1, r2, w, bb)) return false;
	}
	return true;
}

int main() {
	cin >> r1 >> r2 >> w >> b;
	printf("%s\n", check() ? "CHECKMATE" : "OTHER");
	return 0;	
}