#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 1000;

int n, m;
int l[maxn];
int state[maxn];

int makeQuery() {
    cout << "? ";
    for (int i = 0; i < m; i++) {
        cout << state[i];
    }
    cout << endl;
    cout.flush();

    int ans;
    cin >> ans;
    
    return ans;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        state[i] = 1;
        l[i] = makeQuery();
        state[i] = 0;
    }

    vector <pair <int, int> > edges;
    for (int i = 0; i < m; i++) {
        edges.pb(mp(l[i], i));
    }

    sort(edges.begin(), edges.end());
    int curw = 0;
    for (int i = 0; i < m; i++) {
        state[edges[i].sc] = 1;
        int neww = makeQuery();
        if (neww - curw == edges[i].fs) {
            curw = neww;
        } else {
            state[edges[i].sc] = 0;
        }
    }

    cout << "! " << curw << endl;
    cout.flush();

    return 0;
}