#include <bits/stdc++.h>

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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 200500;       
const int MAXQ = 1000500;       
const int MAXK = 1048576;

int t[MAXK * 2 + 3], tid[MAXK * 2 + 3];

void update(int i, int value, int vid) {
    int v = MAXK + i;
    if (t[v] > value)
    	return;
    	
    t[v] = value;
    tid[v] = vid;
    while (v > 1) {
        v /= 2;
        if (t[2 * v] > t[2 * v + 1]) {
        	t[v] = t[2 * v];
        	tid[v] = tid[2 * v];
        } else {
        	t[v] = t[2 * v + 1];
        	tid[v] = tid[2 * v + 1];
        }
    }
}

pii get(int v, int l, int r, int lx, int rx) {  //call with parametres (1, 1, MAXK, zL, zR)
    if ((r < lx) || (rx < l))
        return {-2 * INF, -1};
    if ((lx <= l) && (r <= rx))
        return {t[v], tid[v]};
    return max(get(2 * v, l, (l + r) / 2, lx, rx), get(2 * v + 1, (l + r) / 2 + 1, r, lx, rx));
}

int n, m, sz, maxr, maxrid;
int l[MAXN], r[MAXN], a[MAXN], b[MAXN], c[MAXN]; 
ll ans, cur;
int aid[2], cid[2];
pair<pii, int> q[MAXQ];
int coord[MAXQ], C;

void updAns() {
	if (cur > ans) {
		ans = cur;
		forn(i, 2)
			aid[i] = cid[i];	
	}
}

inline int intersect(int i, int j) {
	return max(0, min(r[i], b[j]) - max(l[i], a[j]));
}

int main() {

    scanf("%d%d", &n, &m);
    C = 0;
    forn(i, n) {
    	scanf("%d%d", &l[i], &r[i]);
    	coord[C++] = l[i];
    	coord[C++] = r[i];	
    }    		
   	forn(i, m) {
    	scanf("%d%d%d", &a[i], &b[i], &c[i]);	
    	coord[C++] = a[i];
    	coord[C++] = b[i];	
    }	    
    
    ans = 0;
    
    sz = 0;
    forn(i, n)
    	q[sz++] = {{l[i], 0}, i};	
    forn(i, m)
    	q[sz++] = {{a[i], 1}, i};	
    sort(q, q + sz);
    
    maxr = -1;
    maxrid = -1;
    forn(i, sz) {
    	int id = q[i].Y;
    	if (q[i].X.Y == 0) {
    		if (maxr < r[id]) {
    			maxr = r[id];
    			maxrid = id;
    		}
    	} else {
    		if (maxrid != -1) {
    			cur = 1ll * c[id] * intersect(maxrid, id);
    			cid[0] = maxrid;
    			cid[1] = id;
    			updAns();
       		}
    	}    	
    }

    //cout << "int " << intersect(1, 0) << '\n';
    
    sz = 0;
    forn(i, n)
    	q[sz++] = {{r[i], 1}, i};	
    forn(i, m)
    	q[sz++] = {{b[i], 0}, i};	
   	sort(q, q + sz);
   		
    maxr = 2 * INF;
    maxrid = -1;
    ford(i, sz) {
    	int id = q[i].Y;
    	if (q[i].X.Y == 1) {
    		if (maxr > l[id]) {
    			maxr = l[id];
    			maxrid = id;
    		}
    	} else {
    		if (maxrid != -1) {
    			cur = 1ll * c[id] * intersect(maxrid, id);
    			cid[0] = maxrid;
    			cid[1] = id;
    			updAns();
       		}
    	}    	
    }    
    /*
    cout << ans << '\n';
    if (ans > 0)
    	cout << aid[0] + 1 << ' ' << aid[1] + 1 << '\n';
    */
    sort(coord, coord + C);
    C = unique(coord, coord + C) - coord;
	//forn(i, C)
	//	cout << coord[i] << '\n';
	
	sz = 0;
    forn(i, n)
    	q[sz++] = {{r[i], 0}, i};	
    forn(i, m)
    	q[sz++] = {{b[i], 1}, i};	
   	sort(q, q + sz);
   	
   	forn(i, sz) {
   		int id = q[i].Y;
   		if (q[i].X.Y == 0) {
   			int pos = lower_bound(coord, coord + C, l[id]) - coord;
   			update(pos, r[id] - l[id], id);
   			//cout << "added " << pos << ' ' << id << '\n';
   		} else {
   			int pos1 = lower_bound(coord, coord + C, a[id]) - coord;
   			int pos2 = lower_bound(coord, coord + C, b[id]) - coord;
   			//cout << "asked " << pos1 << ' ' << pos2 << '\n';
   		
   			pii p = get(1, 1, MAXK, pos1 + 1, pos2 + 1);
   			//cout << p.X << '\n';
   			cur = 1ll * p.X * c[id];
   			//cout << "new: " << cur << '\n';
   			
   			cid[0] = p.Y;
   			cid[1] = id;
   			updAns();		
   		}
   	}   			
   	
    cout << ans << '\n';
    if (ans > 0)
    	cout << aid[0] + 1 << ' ' << aid[1] + 1 << '\n';
    	
	return 0;
}