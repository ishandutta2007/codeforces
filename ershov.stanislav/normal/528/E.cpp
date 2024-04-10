#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 3100;
const long double PI = acos((long double) -1);

int n;

struct point {
    long double x, y;
    point(long double x = 0, long double y = 0) : x(x), y(y) {}

    void print() {
        cerr << x << ' ' << y << endl;
    }
};

long double len(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

point rot90(point a) {
    return point(-a.y, a.x);
}

point operator*(const point & a, long double b) {
    return point(a.x * b, a.y * b);
}
point operator/(const point & a, long double b) {
    return point(a.x / b, a.y / b);
}
long double operator*(const point & a, const point & b) {
    return a.x * b.x + a.y * b.y;
}
long double operator^(const point & a, const point & b) {
    return a.x * b.y - a.y * b.x;
}
point operator+(const point & a, const point & b) {
    return point(a.x + b.x, a.y + b.y);
}
point operator-(const point & a, const point & b) {
    return point(a.x - b.x, a.y - b.y);
}

bool operator<(const point & a, const point & b) {
    return (a ^ b) > -1e-13;
}

struct line {
    point norm;
    long double c;
    line(long double _a = 0, long double _b = 0, long double _c = 0) {
        norm = point(_a, _b);
        c = _c;
    }
};

line lines[N];
long double sq[N], sq2[N], inter_dot[N], dot[N];
int fenw[N], inv[N];
pair<long double, int> up_dot[N], up_inter[N];

void add(int i) {
    for (; i < n + 5; i += (i & (-i))) {
        fenw[i]++;
    }
}

int get(int i) {
    int ans = 0;
    for (; i > 0; i -= (i & (-i))) {
        ans += fenw[i];
    }
    return ans;
}

//bool comp_inter(int a, int b) {
//    return inter_dot[a] > inter_dot[b];
//}
//
//bool comp_dot(int a, int b) {
//    return dot[a] > dot[b];
//}

long double get_square(point inter, point a, point b) {
//    a.print();
//    b.print();
    long double c = a * a;
    long double d = (inter * a);
    long double e = inter * inter - 4e12;
    a = a * ((-d + sqrt(d * d - c * e)) / (c));
    c = b * b;
    d = (inter * b);
    b = b * ((-d + sqrt(d * d - c * e)) / (c));
//    a.print();
//    b.print();
    long double ans = 0;
    a = a + inter;
    b = b + inter;
    ans += inter ^ (a - b);
    ans += 2e12 * acos(a * b / (len(a) * len(b)));
//    cout << "ans = " << ans << endl;
    return ans;
}

bool comp(const pair<double, int> & a, const pair<double, int> & b) {
    return a.fs < b.fs;
}

long double solve(point tangent, point on, int num) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i != num) {
            long double mv = -(on * lines[i].norm + lines[i].c) / (tangent * lines[i].norm);
            point inter = on + tangent * mv;
            point tangent2 = rot90(lines[i].norm);
            if ((tangent2 ^ tangent) < 0) {
                tangent2 = tangent2 * (-1);
            }
            sq[i] = get_square(inter, tangent2, tangent);
            sq2[i] = get_square(inter, tangent2 * (-1), tangent * (-1));
            inter_dot[i] = inter * tangent;
            dot[i] = tangent2 * tangent;
            up_dot[j] = make_pair(dot[i], i);
            up_inter[j] = make_pair(inter_dot[i], i);
            j++;
        }
    }
    sort(up_dot, up_dot + n - 1, comp);
    sort(up_inter, up_inter + n - 1, comp);
    reverse(up_dot, up_dot + n - 1);
    reverse(up_inter, up_inter + n - 1);
    for (int i = 0; i < n - 1; i++) {
        inv[up_inter[i].sc] = i + 1;
    }
    for (int i = 0; i < n + 5; i++) {
        fenw[i] = 0;
    }
    long double ans = 0;
    int all = 0;
    for (int i = 0; i < n - 1; i++) {
        int cnt = get(inv[up_dot[i].sc]);
        ans += cnt * sq[up_dot[i].sc] + (all - cnt) * sq2[up_dot[i].sc];
        add(inv[up_dot[i].sc]);
        all++;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    //n = 3000;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //a = rand() % 100000;
        //b = rand() % 100000;
        //c = rand() % 100000;
        lines[i] = line(a, b, c);
        long double l = len(lines[i].norm);
        lines[i].norm = lines[i].norm / l;
        lines[i].c /= -l;
    }
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        point on = lines[i].norm * (-lines[i].c);
        ans += solve(rot90(lines[i].norm), on, i);
    }
    ans = ans / (n * 1.0 * (n - 1) * 1.0 * (n - 2) / 6.0);
    printf("%.10lf\n", double (PI * 4e12 - ans) / 2);
    return 0;
}