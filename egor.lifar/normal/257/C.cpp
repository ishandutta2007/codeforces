#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>


using namespace std;


const double Pi = acos(-1);
int n;
double x[100000], y[100000];
vector< pair<double, int> > v;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(atan2(y[i], x[i]), i));
    }
    sort(v.begin(), v.end());
    v.push_back(make_pair(v[0].first + 2 * Pi, v[0].second));
    double s = -1.0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first - v[i - 1].first > s) {
            s = v[i].first - v[i - 1].first;
        }
    }
    s = 2 * Pi - s;
    s = (s / (2 * Pi)) * 360;
    printf("%.10lf\n", s);
    return 0;
}