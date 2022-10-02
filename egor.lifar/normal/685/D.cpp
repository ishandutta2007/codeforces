#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;


#define INF -1700000000


struct query {
    int row, l, r; 
    bool a;
    int lbl, ubr;
    query(){}
    query(int _row, int _l, int _r, bool _a) {
        row = _row; 
        l = _l; 
        r = _r; 
        a = _a;
    }
};


bool operator <(const query&a, const query& b) {
    return a.row < b.row;
}


int n, k;


int main() {
    scanf("%d %d", &n, &k);
    vector<pair<int, int> > points;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].first, &points[i].second);
    }
    sort(points.begin(), points.end());
    vector<int> vx;
    for (int i = 0; i < n; i++) {
        int st;
        if (vx.empty()) {
            st = points[i].first - k + 1;
        } else {
            st = max(vx.back() + 1, points[i].first - k + 1);
        }
        for (int j = st; j <= points[i].first; j++) {
            vx.push_back(j);
        }
    }
    vector<query> vq;
    for (int i = 0; i < n; i++) {
        vq.push_back(query(points[i].second - k + 1, points[i].first - k + 1, points[i].first, 1));
        vq.push_back(query(points[i].second + 1, points[i].first - k + 1, points[i].first, 0));
    }
    for (int i = 0; i < (int)vq.size(); i++) {
        vq[i].lbl = lower_bound(vx.begin(), vx.end(), vq[i].l) - vx.begin();
        vq[i].ubr = upper_bound(vx.begin(), vx.end(), vq[i].r) - vx.begin();
    }
    int cntx = vx.size();
    vx.clear();
    vx.shrink_to_fit();
    sort(vq.begin(), vq.end());
    vector<int> vec;
    vec.resize(cntx);
    vector<int> last;
    last.resize(cntx);
    for (int i = 0; i < cntx; i++) {
        last[i] = INF;
    }
    vector<long long> ans;
    ans.resize(n);
    for (int ii = 0; ii < (int)vq.size(); ii++) {
        int lbl = vq[ii].lbl;
        int ubr = vq[ii].ubr;
        for (int i = lbl; i < ubr; i++) {
            if (last[i] != INF && vec[i] != 0) {
                ans[vec[i] - 1] += vq[ii].row - last[i];
            }
            if (vq[ii].a){
                vec[i]++;
            } else {
                vec[i]--;
            }
            last[i] = vq[ii].row;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}