

#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 100100
using namespace std;
struct Range {
	int x, y1, y2, num;
	bool operator<(const Range &p)const {
		return y1 < p.y1;
	}
};
set<Range>Set;
int Bx, By, Ex, Ey, UF[N_];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
struct Seg {
	int x, y1, y2;
	bool operator<(const Seg &p)const {
		return x < p.x;
	}
}w[N_];
struct point {
	int x, y;
}P[N_];
struct Rect {
	int bx, by, ex, ey;
	bool operator<(const Rect &p)const {
		return by < p.by;
	}
}R[N_];
int n, cnt, RC, Res;
void Add(int x1, int y1, int x2, int y2) {
	x1 = max(x1, Bx);
	x2 = min(x2, Ex);
	y1 = max(y1, By);
	y2 = min(y2, Ey);
	if (x1 < x2 && y1 < y2) {
		R[++RC] = { x1,y1,x2,y2 };
		UF[RC] = RC;
	}
}
void Del(set<Range>::iterator it, Range tp) {
	vector<Range>TP;
	for (auto it2 = it; it2 != Set.end(); ) {
		int y1 = max(tp.y1, it2->y1);
		int y2 = min(tp.y2, it2->y2);
		if (y1 >= y2)break;
		Add(it2->x, y1, tp.x, y2);
		TP.push_back({ it2->x, it2->y1, y1 });
		TP.push_back({ it2->x, y2, it2->y2 });
		auto tt = it2;
		it2++;
		Set.erase(tt);
	}
	for (auto &t : TP) {
		if (t.y1 < t.y2) {
			Set.insert(t);
		}
	}
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b) {
		UF[a] = b;
		Res--;
	}
}
void Del2(set<Range>::iterator bit, Range tp, int by) {
	vector<Range>TP;
	for (auto it = bit; it != Set.end();) {
		int y1 = max(tp.y1, it->y1);
		int y2 = min(tp.y2, it->y2);
		if (y1 >= y2)break;
		if (it->x == by) {
			Merge(it->num, tp.num);
		}
		TP.push_back({ it->x, it->y1, y1 });
		TP.push_back({ it->x, y2, it->y2 });
		auto tt = it;
		it++;
		Set.erase(tt);
	}
	for (auto &t : TP) {
		if (t.y1 < t.y2) {
			Set.insert(t);
		}
	}
	Set.insert(tp);
}
int main() {
	int i, j;
	scanf("%d%d%d%d", &Bx, &Ey, &Ex, &By);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &P[i].x, &P[i].y);
	}
	P[n] = P[0];
	for (i = 0; i < n; i++) {
		if (P[i].x == P[i + 1].x) {
			w[cnt++] = { P[i].x, min(P[i].y,P[i + 1].y),max(P[i].y,P[i + 1].y) };
		}
	}
	sort(w, w + cnt);
	for (i = 0; i < cnt; i++) {
		auto it = Set.lower_bound({ w[i].x,w[i].y1,w[i].y2 });
		Range tp = { w[i].x,w[i].y1,w[i].y2 };
		if (Set.empty()) {
			Set.insert(tp);
			continue;
		}
		if (it != Set.begin())it--;
		if (it->y2 <= tp.y1)it++;
		if (it == Set.end() || it->y1 >= w[i].y2 || it->y2 <= w[i].y1) {
			Set.insert(tp);
		}
		else {
			Del(it, tp);
		}
	}
	sort(R + 1, R + RC + 1);
	Res = RC;
	for (i = 1; i < RC; i++) {
		for (j = i + 1; j <= RC; j++) {
			if (R[i].ey == R[j].by && max(R[i].bx, R[j].bx) < min(R[i].ex, R[j].ex)) {
				Merge(i, j);
			}
		}
	}
	printf("%d\n", Res);
}