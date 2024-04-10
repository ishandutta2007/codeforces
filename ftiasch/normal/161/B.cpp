#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

const int N = 1111;

int n, m, cost[N], type[N];
vector <int> stools, pencils;

bool compare(int i, int j) {
    return cost[i] > cost[j];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", cost + i, type + i);
        if (type[i] == 1) {
            stools.push_back(i);
        } else {
            pencils.push_back(i);
        }
    }
    sort(stools.begin(), stools.end(), compare);
    vector <vector <int> > groups(m);
    if ((int)stools.size() >= m) {
        for (int i = 0; i < m; ++ i) {
            groups[i].push_back(stools[i]);
        }
        for (int i = m; i < (int)stools.size(); ++ i) {
            groups[m - 1].push_back(stools[i]);
        }
        for (int i = 0; i < (int)pencils.size(); ++ i) {
            groups[m - 1].push_back(pencils[i]);
        }
    } else {
        for (int i = 0; i < (int)stools.size(); ++ i) {
            groups[i].push_back(stools[i]);
        }
        for (int i = (int)stools.size(); i < m; ++ i) {
            groups[i].push_back(pencils[i - (int)stools.size()]);
        }
        for (int i = m - (int)stools.size(); i < (int)pencils.size(); ++ i) {
            groups[m - 1].push_back(pencils[i]);
        }
    }
    long long result = 0;
    for (int i = 0; i < n; ++ i) {
        result += 2 * cost[i];
    }
    for (vector <vector <int> > :: iterator g = groups.begin(); g != groups.end(); ++ g) {
        int minimum = INT_MAX;
        bool found = false;
        for (vector <int> :: iterator iter = g->begin(); iter != g->end(); ++ iter) {
            if (type[*iter] == 1) {
                found = true;
            }
            minimum = min(minimum, cost[*iter]);
        }
        if (found) {
            result -= minimum;
        }
    }
    cout << (result / 2) << "." << 5 * (result % 2) << endl;
    for (vector <vector <int> > :: iterator g = groups.begin(); g != groups.end(); ++ g) {
        printf("%d", g->size());
        for (vector <int> :: iterator iter = g->begin(); iter != g->end(); ++ iter) {
            printf(" %d", *iter + 1);
        }
        puts("");
    }
    return 0;
}