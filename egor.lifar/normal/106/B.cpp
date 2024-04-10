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

struct type{
    double speed, ram, hdd, cost;
};


type m[100];
vector< pair<int, int> > v;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i].speed >> m[i].ram >> m[i].hdd >> m[i].cost;
        //cout << m[i].speed << m[i].ram << m[i].hdd << m[i].cost << endl;
    }
    for (int i = 0; i < n; i++) {
        bool b = true;
        for (int j = 0; j < n; j++) {
            if (m[i].speed < m[j].speed && m[i].ram < m[j].ram && m[i].hdd < m[j].hdd) {
                b = false;
            }
        }
        if (b) {
            v.push_back(make_pair(m[i].cost, i));
        }
    }
    int s = 1000000001;
    int k = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (s > v[i].first) {
            s = v[i].first;
            k = v[i].second;
        }
    } 
    cout << k + 1 << endl;
    return 0;
}