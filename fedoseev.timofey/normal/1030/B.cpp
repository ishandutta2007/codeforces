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
    ll x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    void scan() {
        cin >> x >> y;
    }
    void print() {
        cout << x << " " << y << "\n";
    }
    ll operator*(const point &p) const {
        return x * p.x + y * p.y;
    }
    ll operator%(const point &p) const {
        return x * p.y - y * p.x;
    }
    bool operator==(const point &p) const {
        return x == p.x && y == p.y;
    }
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    bool is_on_line(point &A, point &B) {
        return (((A - *this) % (B - *this)) == 0);
    }
    bool is_on_segment(point &A, point &B) {
        return (*this).is_on_line(A, B) && ((A - *this) * (B - *this) <= 0);
    }
    double length() {
        return sqrt(double((*this) * (*this)));
    }
    double dist_to(const point &A, const point &B) const {
        ll cur = abs((A - *this) % (B - *this));
        return (double)cur / (A - B).length();
    }
};

vector <point> polygon;


bool in(point &A) {
	for (int i = 0; i + 1 < polygon.size(); ++i) {
	    if (A.is_on_segment(polygon[i], polygon[i + 1])) {
	        return 1;
	        return 0;
	    }
	}
	int cnt = 0;
	for (int i = 0; i + 1 < polygon.size(); ++i) {
	    int b = i, t = i + 1;
	    if (polygon[i].y > polygon[i + 1].y) {
	        swap(b, t);
	    }
	    if (polygon[b].y <= A.y && A.y < polygon[t].y && (polygon[t] - polygon[b]) % (A - polygon[b]) > 0) {
	        ++cnt;
	    }
	}
	if (cnt % 2 == 0) {
	    return 0;
	}
	else {
	    return 1;
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, d;
    cin >> n >> d;
    int q;
    cin >> q;
    polygon = {{0, d}, {d, 0}, {n, n - d}, {n - d, n}, {0, d}};
    for (int i = 0; i < q; ++i) {
    	point A;
    	cin >> A.x >> A.y;
    	if (in(A)) cout << "YES\n";
    	else cout << "NO\n";
    }
    
}