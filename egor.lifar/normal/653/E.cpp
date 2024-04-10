#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


set<pair<int,int> > bad;
set<int> r;


bool norm(int a, int b) {
    if(a > b) {
        swap(a, b);
    }
    return bad.find(make_pair(a, b)) == bad.end();
}


void dfs(int a) {
    vector<int> mt;
    for(int b : r) {
        if(norm(a, b)) {
            mt.push_back(b);
        }
    }
    for(int i = 0; i < (int)mt.size(); i++) {
        int b = mt[i];
        r.erase(b);
    }
    for(int i = 0; i < (int)mt.size(); i++) {
        int b = mt[i];
        dfs(b);
    }
}


int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 2; i <= n; i++) {
        r.insert(i);
    }
    int maxdeg = n - 1;
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) {
            swap(a, b);
        }
        if(a == 1) {
            maxdeg--;
        }
        bad.insert(make_pair(a, b));
    }
    if(maxdeg < k) {
        cout << "impossible" << endl;
        return 0;
    }
    int comp = 0;
    for(int i = 2; i <= n; i++) {
        if(norm(1, i) && r.find(i) != r.end()) {
            dfs(i);
            comp++;
        }
    }
    if(!r.empty()) {
        cout << "impossible" << endl;
        return 0;
    }
    if(comp > k) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    return 0;
}