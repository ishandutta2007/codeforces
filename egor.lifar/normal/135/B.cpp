#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>    


using namespace std;


#define eps 0.00001


struct point{
    double x, y;
    point(){}
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
};


point p[8];
vector<bool> v;


bool pryam(vector<point> v) {
    int a[4] = {0, 1, 2, 3};
    do {
        bool b = true;
        for (int i = 0; i < 4; i++) {
            int j = (i - 1 + 4) % 4;
            int k = (i + 1) % 4;
            double s = (v[a[j]].x - v[a[i]].x) * (v[a[k]].x - v[a[i]].x);
            s += (v[a[j]].y - v[a[i]].y) * (v[a[k]].y - v[a[i]].y);
            if (s > eps) {
                b = false;
            }
        }
        if (b) {
            return true;
        }
    } while(next_permutation(a, a + 4));
    return false;
}


bool kvadr(vector<point> v) {
    int a[4] = {0, 1, 2, 3};
    do {
        bool b = true;
        for (int i = 0; i < 4; i++) {
            int j = (i - 1 + 4) % 4;
            int k = (i + 1) % 4;
            double s = (v[a[j]].x - v[a[i]].x) * (v[a[k]].x - v[a[i]].x);
            s += (v[a[j]].y - v[a[i]].y) * (v[a[k]].y - v[a[i]].y);
            if (s > eps) {
                b = false;
            }
        }
        bool b1 = true;
        vector<double> t;
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            t.push_back(sqrt((v[a[j]].x - v[a[i]].x) * (v[a[j]].x - v[a[i]].x) + (v[a[j]].y - v[a[i]].y) * (v[a[j]].y - v[a[i]].y)));
        }
        if (abs(t[0] - t[1]) > eps || abs(t[1] - t[2]) > eps || abs(t[2] - t[3]) > eps) {
            b1 = false;
        }
        if (b && b1) {
            return true;
        }
    } while(next_permutation(a, a + 4));
    return false;
}


void get(int i) {
    if (i == 8) {
        vector<point> kv, pr;
        vector<int> kvi, pri;
        for (int j = 0; j < (int)v.size(); j++) {
            if (v[j]) {
                pr.push_back(p[j]);
                pri.push_back(j + 1);
            } else {
                kv.push_back(p[j]);
                kvi.push_back(j + 1);
            }
        }
        if (kv.size() != 4) {
            return;
        }
        if (pryam(pr) && kvadr(kv)) {
            cout << "YES" << endl;
            for (int j = 0; j < (int)kvi.size(); j++) {
                cout << kvi[j] << ' ';
            }
            cout << endl;
            for (int j = 0; j < (int)pri.size(); j++) {
                cout << pri[j] << ' ';
            }
            cout << endl;
            exit(0);
        }
        return;
    }
    v.push_back(0);
    get(i + 1);
    v.pop_back();
    v.push_back(1);
    get(i + 1);
    v.pop_back();
}


int main() {
    for (int i = 0; i < 8; i++) {
        cin >> p[i].x >> p[i].y;
    }
    get(0);
    cout << "NO" << endl;
    return 0;
}