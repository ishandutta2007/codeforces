/*
 












 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";


struct point
{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};



int dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


point operator -(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

int n;
point p[3];
int r[3];


bool operator ==(point a, point b) {
    return a.x == b.x && a.y == b.y;
}


bool notintersect1(int i, int j) {
    return dist(p[i], p[j]) > (r[i] + r[j]) * (r[i] + r[j]) || dist(p[i], p[j]) < (r[j] - r[i]) * (r[j] - r[i]);
}

bool notintersect(int i, int j) {
    return dist(p[i], p[j]) >= (r[i] + r[j]) * (r[i] + r[j]) || dist(p[i], p[j]) <= (r[j] - r[i]) * (r[j] - r[i]);
}

bool intersect(int i, int j) {
    //cout << p[i].x << ' ' << p[i].y << ' ' << p[j].x << ' ' << p[j].y << ' ' << dist(p[i], p[j]) << endl;
    return dist(p[i], p[j]) < (r[i] + r[j]) * (r[i] + r[j]) && !(dist(p[i], p[j]) <= (r[j] - r[i]) * (r[j] - r[i]));
}


bool cas(int i, int j) {
    return dist(p[i], p[j]) == (r[i] + r[j]) * (r[i] + r[j]) || dist(p[i], p[j]) == (r[i] - r[j]) * (r[i] - r[j]);
}   



bool on(int i, double x, double y) {
 //   cout << sqrt((p[i].x - x) * (p[i].x - x) + (p[i].y - y) * (p[i].y - y)) << endl;
    return abs(sqrt((p[i].x - x) * (p[i].x - x) + (p[i].y - y) * (p[i].y - y)) - r[i]) < 1e-9;
}


bool check1() {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int k = 0;
            while (k == i || k == j) {
                k++;
            }
            point q = p[j] - p[i];
            double dist = sqrt(q.x * q.x + q.y * q.y);
            int f = r[j] * r[j] - r[i] * r[i];
            double diff = double(f) / dist;
            double a = dist - (diff + dist) / 2;
            double x1 = q.x;
            double y1 = q.y;
            double d1 = sqrt(x1 * x1 + y1 * y1);
            x1 /= d1;
            y1 /= d1;
            x1 = p[i].x + x1 * a;
            y1 = p[i].y + y1 * a;
            swap(q.x, q.y);
            q.x *= -1;
            double x = q.x;
            double y = q.y;
            double d = sqrt(x * x + y * y);
            x /= d;
            y /= d;
            double h = sqrt(r[i] * r[i] - a * a);
            x *= h;
            y *= h;
            if (on(k, x1 + x, y1 + y) && on(k, x1 - x, y1 - y)) {
            //    cout << i + 1 << ' ' << j + 1 << endl;
              //  cout << x << ' ' << y << endl;
                return true;
            }
        }
    } 
    return false;
}


bool check() {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int k = 0;
            while (k == i || k == j) {
                k++;
            }
            point q = p[j] - p[i];
            double dist = sqrt(q.x * q.x + q.y * q.y);
            int f = r[j] * r[j] - r[i] * r[i];
            double diff = double(f) / dist;
            double a = dist - (diff + dist) / 2;
            double x1 = q.x;
            double y1 = q.y;
            double d1 = sqrt(x1 * x1 + y1 * y1);
            x1 /= d1;
            y1 /= d1;
            x1 = p[i].x + x1 * a;
            y1 = p[i].y + y1 * a;
            swap(q.x, q.y);
            q.x *= -1;
            double x = q.x;
            double y = q.y;
            double d = sqrt(x * x + y * y);
            x /= d;
            y /= d;
            double h = sqrt(r[i] * r[i] - a * a);
            x *= h;
            y *= h;
            if (on(k, x1 + x, y1 + y)) {
            //    cout << i + 1 << ' ' << j + 1 << endl;
              //  cout << x << ' ' << y << endl;
                return true;
            }
            if (on(k, x1 - x, y1 - y)) {
                return true;
            }
        }
    } 
    return false;
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> r[i];
    }
    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 2) {
        if (intersect(0, 1)) {
            cout << 4 << endl;
        } else {
            cout << 3 << endl;
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (notintersect1(i, (i + 1) % n) && notintersect1(i, (i + 2) % n)) {
            swap(p[i], p[2]);
            swap(r[i], r[2]);
            if (intersect(0, 1)) {
                cout << 5 << endl;
            } else {
                cout << 4 << endl;
            }
            return 0;
        }   
    }
    //cout << "opa" << endl;
    if (p[0] == p[1] && p[1] == p[2]) {
        cout << 4 << endl;
        return 0;
    }
    if (p[0] == p[1]) {
        if (intersect(2, 0) && intersect(2, 1)) {
            cout << 6 << endl;
            return 0;
        }
        cout << 5 << endl;
        return 0;
    }
    if (p[0] == p[2]) {
        if (intersect(1, 0) && intersect(2, 1)) {
            cout << 6 << endl;
            return 0;
        }
        cout << 5 << endl;
        return 0;
    }
    if (p[2] == p[1]) {
        if (intersect(2, 0) && intersect(0, 1)) {
            cout << 6 << endl;
            return 0;
        }
        cout << 5 << endl;
        return 0;
    }
    int sum = r[0] + r[1] + r[2];
    if (cas(0, 1) && cas(0, 2) && cas(1, 2) && max(max(r[0], r[1]), r[2]) == sum - max(max(r[0], r[1]), r[2])) {
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (r[i] > r[pos]) {
                pos = i;
            }
        }
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (i != pos) {
                if (dist(p[pos], p[i]) > r[pos] * r[pos]) {
                    bad = true;
                }
            }
        }
        bool bad1 = false;
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (i != pos) {
                if (dist(p[pos], p[i]) < r[pos] * r[pos]) {
                    bad1 = true;
                }
                st.push_back(i);
            }
        }
       // if ()
        if (!bad || !bad1) {
        if (bad ||(!bad && dist(p[st[0]], p[st[1]]) == (max(max(r[0], r[1]), r[2]) * 2 - (sum - max(max(r[0], r[1]), r[2]))) * (max(max(r[0], r[1]), r[2]) * 2 - (sum - max(max(r[0], r[1]), r[2]))))) {
            cout << 5 << endl;
            return 0;
        }
    }
    }
    if (notintersect(0, 1) && notintersect(0, 2) && notintersect(1, 2)) {
        cout << 4 << endl;
        return 0;
    }
    if (cas(0, 1) && cas(0, 2)) {
        cout << 6 << endl;
        return 0;
    }
    if (cas(2, 1) && cas(0, 2)) {
        cout << 6 << endl;
        return 0;
    }
    if (cas(0, 1) && cas(1, 2)) {
        cout << 6 << endl;
        return 0;
    }
    if (notintersect(0, 1) && notintersect(0, 2)) {
        cout << 5 << endl;
        return 0;
    }
    if (notintersect(2, 1) && notintersect(0, 2)) {
        cout << 5 << endl;
        return 0;
    }
    if (notintersect(1, 0) && notintersect(1, 2)) {
        cout << 5 << endl;
        return 0;
    }
    if (check1() || (check() && (cas(0, 1) || cas(0, 2) || cas(1, 2)))) {
        cout << 6 << endl;
        return 0;
    }
    if (check()) {
        cout << 7 << endl;
        return 0;
    }
    if (cas(0, 1) || cas(0, 2) || cas(1, 2)) {
        cout << 7 << endl;
        return 0;
    }
    if (intersect(0, 1) && intersect(1, 2) && intersect(0, 2)) {
        cout << 8 << endl;
        return 0;
    }
    cout << 6 << endl;
    return 0;          
}