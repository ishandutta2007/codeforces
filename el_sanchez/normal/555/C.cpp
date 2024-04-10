#include <bits/stdc++.h>
#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second                    
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 400500;
const int MAXK = 524288;

int n, m, p;
int x[MAXN], y[MAXN], tp[MAXN];
vi coord;
char c;

struct vertex {
    int val, upd;
    bool flag;
    
    vertex() {val = upd = flag = 0;}
};
                 
vertex t[2][MAXK * 2 + 3];

//!!!
//tree: numeration from 1
//array: numeration from 0

void push(int id, int v, int l, int r) {
    if (t[id][v].flag) {
        if (v < MAXK) {
            t[id][2 * v].flag = t[id][2 * v + 1].flag = 1;
            t[id][2 * v].upd = max(t[id][2 * v].upd, t[id][v].upd);
            t[id][2 * v + 1].upd = max(t[id][2 * v + 1].upd, t[id][v].upd);
            t[id][2 * v].val = max(t[id][2 * v].val, t[id][v].upd);
            t[id][2 * v + 1].val = max(t[id][2 * v + 1].val, t[id][v].upd);
        }
        t[id][v].upd = 0;
        t[id][v].flag = 0;
    }
}

void update(int id, int v, int l, int r, int lx, int rx, int x) { //[lx, rx)
    push(id, v, l, r);
    if ((r <= lx) || (rx <= l))
        return;
    if ((lx <= l) && (r <= rx)) {
        t[id][v].flag = 1;
        t[id][v].upd = max(t[id][v].upd, x);
        t[id][v].val = max(t[id][v].val, x);
        return;
    }
    
    update(id, 2 * v, l, (l + r) >> 1, lx, rx, x);
    update(id, 2 * v + 1, (l + r) >> 1, r, lx, rx, x);
    if (t[id][2 * v].val > t[id][2 * v + 1].val)
        t[id][v].val = t[id][2 * v].val;
    else
        t[id][v].val = t[id][2 * v + 1].val;
}

int get(int id, int v, int l, int r, int lx, int rx) { //[lx, rx)
    push(id, v, l, r);
    if ((r <= lx) || (rx <= l))
        return 0;
    if ((lx <= l) && (r <= rx))
        return t[id][v].val;

    int t1 = get(id, 2 * v, l, (l + r) >> 1, lx, rx);
    int t2 = get(id, 2 * v + 1, (l + r) >> 1, r, lx, rx);
    if (t1 > t2)
        return t1;
    return t2;
}

void update(int id, int l, int r, int x) { //[l, r]
    return update(id, 1, 1, MAXK + 1, l + 1, r + 2, x);
}

int get(int id, int l, int r) { //[l, r]
    return get(id, 1, 1, MAXK + 1, l + 1, r + 2);
}

int px, py;

int main() {

	scanf("%d%d\n", &m, &n);
	forn(i, n) {
		scanf("%d %d %c\n", &x[i], &y[i], &c);
		swap(x[i], y[i]);
		coord.pb(x[i]);
		coord.pb(y[i]);
		if (c == 'U')
			tp[i] = 0;
		else
			tp[i] = 1;	
	}

	coord.pb(0);
	coord.pb(m + 1);	
	sort(all(coord));
	p = unique(coord.begin(), coord.end()) - coord.begin();
	coord.resize(p); 

	forn(i, n) {
		//cout << x[i] << ' ' << y[i] << ' ' << tp[i] << '\n';
		px = lower_bound(all(coord), x[i]) - coord.begin();
		py = lower_bound(all(coord), y[i]) - coord.begin();
		if (tp[i] == 0) {
			int v = get(0, py, py);
			//cout << "FROM " << coord[px] << " TO " << coord[v] << '\n';
			printf("%d\n", coord[px] - coord[v]);
			update(0, py, py, px);
			update(1, v, px, py);
		} else {
			int v = get(1, px, px);
			//cout << "FROM " << coord[py] << " TO " << coord[v] << '\n';
			printf("%d\n", coord[py] - coord[v]);
			update(1, px, px, py);
			update(0, v, py, px);
		}
	}
	
	return 0;
}