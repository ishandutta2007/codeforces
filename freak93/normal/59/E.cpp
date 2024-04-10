#include <iostream>
#include <vector>
#include <map>
#define x first
#define y second

using namespace std;

const int maxn = 3005;
const int maxm = 40005;
const int maxk = 100005;

int n, i, p, q, rez, m, k, x, y, z, queue[maxm], w;

pair<int, int> muc[maxm];
vector<int> E[maxn];

int dis[maxm], back[maxm];
map<int, int> nuvoie, muchii;
map<int, int>::iterator a, b;

void afis(int x) {
	if (muc[x].x == 1)
		cout << 1 << " " << muc[x].y << " ";
	else
		afis(back[x]),
			cout << muc[x].y << " ";
}

int main() {
	cin >> n >> m >> k;
	for (i = 1; i <= m; ++i)
		cin >> muc[i].x >> muc[i].y, muc[m + i].x = muc[i].y, muc[m + i].y = muc[i].x,
		E[muc[i].x].push_back(i),
		E[muc[i].y].push_back(m + i),
		muchii[muc[i].x * 5000 + muc[i].y] = i, muchii[muc[i].y * 5000 + muc[i].x] = m + i;

	for (i = 1; i <= k; ++i) {
		cin >> x >> y >> z;
		if ((a = muchii.find(x * 5000 + y)) != muchii.end() && (b = muchii.find(y * 5000 + z)) != muchii.end())
			nuvoie[a -> second * 25000 + b -> second] = 1;
	}

	p = 1;
	for (vector<int>::iterator it = E[1].begin(); it != E[1].end(); ++it)
		queue[++q] = *it, dis[*it] = 1;

	for (; p <= q; ++p) {
		x = queue[p];
		y = muc[x].y;
		for (vector<int>::iterator it = E[y].begin(); it != E[y].end(); ++it)
			if (dis[*it] == 0 && nuvoie.find(x * 25000 + *it) == nuvoie.end())
				queue[++q] = *it, dis[*it] = dis[x] + 1, back[*it] = x;
	}

	rez = m * 5000;

	for (i = 1; i <= 2 * m; ++i) {
		if (muc[i].y == n && dis[i] != 0)
			if (dis[i] < rez)
				rez = dis[i], w = i;
	}
	if (rez == m * 5000)
		rez = -1;
	cout << rez << "\n";
	if (rez == -1)
		return 0;
	afis(w);
}