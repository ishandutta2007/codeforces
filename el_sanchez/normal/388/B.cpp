#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cassert>


using namespace std;


#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;  //!!
const ld eps = 1e-7;  //!!
    
int n, nn, vertexes, maxst;
bool isst[31];
int id[31], needway[31];  
vector<vi> g;
vi emp;

void addedge(int v, int w) {
	g[v].pb(w);
	g[w].pb(v);
}

void gen(int len) {
	vertexes = 2;
	int last = 0;
	g.pb(emp);
	g.pb(emp);
	for (int i = 0; i < len; i++) {
		g.pb(emp);
		g.pb(emp);
		g.pb(emp);
		addedge(last, vertexes);
		addedge(last, vertexes + 1);
		addedge(vertexes, vertexes + 2);
		addedge(vertexes + 1, vertexes + 2);
        last = vertexes + 2;
        id[len - i - 1] = last;
        needway[len - i - 1] = (i + 1) * 2;
        vertexes += 3;
	}
	addedge(vertexes - 1, 1);

	for (int i = len - 1; i >= 0; i--) {
		if (isst[i]) {
			int iid = id[i];
			last = 0;
			forn(j, needway[i] - 1) {
				g.pb(emp);
				addedge(last, vertexes);
				last = vertexes;
				vertexes++;
			}
			addedge(last, iid);
		}
	}
}

int main() {

    cin >> n;
    nn = n;
    maxst = 0;
    for (int i = 0; i < 31; i++) {
    	if (nn & 1) {
    		maxst = i;
    		isst[i] = 1;
    	}
    	nn >>= 1;
    } 
    
    if (n == 1) {
    	vertexes = 2;
    	g.resize(2);
    	g[0].pb(1);
    	g[1].pb(0);
    } else {
    	gen(maxst);
    }

    cout << vertexes << '\n';
    string s;
    forn(i, vertexes)
    	s += ' ';
    forn(i, vertexes) {
    	forn(j, vertexes)
    		s[j] = 'N';
    	forn(j, g[i].size())
    		s[g[i][j]] = 'Y';
    	cout << s << '\n';	
    }

    return 0;
}