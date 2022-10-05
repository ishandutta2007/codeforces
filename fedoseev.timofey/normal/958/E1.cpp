#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point() : x(0), y(0) {}
    void scan() {
        cin >> x >> y;
    }
    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
    int operator*(const point &other) const {
        return x * other.x + y * other.y;
    }
    int operator%(const point &other) const {
        return x * other.y - y * other.x;
    }
    bool operator<(const point &other) const {
        return make_pair(x, y) < make_pair(other.x, other.y);
    }
};

bool differentSides(const point &A, const point &B, const point &C, const point &D) {
    return (ll)((A - B) % (C - B)) * ((A - B) % (D - B)) < 0;
}

bool intersect(const point &A, const point &B, const point &C, const point &D) {
    return differentSides(A, B, C, D) && differentSides(C, D, A, B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int r, b;
    cin >> r >> b;
    vector <point> u(r), v(b);
    for (int i = 0; i < r; ++i) {
        u[i].scan();
    }
    for (int i = 0; i < b; ++i) {
        v[i].scan();
    }
    if (r != b) {
        cout << "No\n";
        return 0; 
    }
    sort(u.begin(), u.end());
    do {
        bool bad = false;
        for (int i = 0; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                if (intersect(u[i], v[i], u[j], v[j])) {
                    bad = true;
                    break;
                }
            }
            if (bad) break;
        }
        if (!bad) {
            cout << "Yes\n";
            return 0;
        }
    }
    while (next_permutation(u.begin(), u.end()));
    cout << "No\n"; 
}