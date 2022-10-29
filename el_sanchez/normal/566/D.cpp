//#define _GLIBCXX_DEBUG
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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 200500;
    
int n, q;
int t, x, y;
int rt[MAXN], rk[MAXN], nxt[MAXN], prv[MAXN], lead[MAXN], l, r, ii;

void makeSets(int v) {
	rt[v] = v;
	rk[v] = 0;
}

int findSet(int v) {
	if (rt[v] != v)
		rt[v] = findSet(rt[v]);
	return rt[v];
}

void unionSets(int a, int b) {
	int x = findSet(a);
	int y = findSet(b);
	if (x != y) {
		if (rk[x] > rk[y])
			rt[y] = x;
		else
			rt[x] = y;
		if (rk[x] == rk[y])
			rk[y]++;
	}
}

int main() {

    scanf("%d%d", &n, &q);
    forn(i, n)
    	makeSets(i);

    forn(i, n) {
    	nxt[i] = i + 1;
    	prv[i] = i - 1;
    	lead[i] = i;
    }
    
    forn(i, q) {
    	scanf("%d%d%d", &t, &x, &y);
    	x--;
    	y--;
    	
    	if (t == 1) {
    		unionSets(x, y);
    	} else if (t == 3) {
    		cout << (findSet(x) == findSet(y) ? "YES\n" : "NO\n");	
    	} else {
    		x = lead[x];
    		//cout << "start\n";
    		int i;
    		for (i = x; i <= y; ) {
    			//db(i);
    			assert(i != nxt[i]);
    			i = nxt[i];

       			if (i <= y)
    				unionSets(x, i);
    			if (i > y)
    				break;      
    			
    			l = prv[i];
    			r = nxt[i];
    			if (l != -1)
    				nxt[l] = r;
    			if (r != n)
    				prv[r] = l;
    			lead[i] = x;
    		}
    		nxt[x] = i;
    		if (i != n)
    			prv[i] = x;  	
    	}    
    }
    
	return 0;
}