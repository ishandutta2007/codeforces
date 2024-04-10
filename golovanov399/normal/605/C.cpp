#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const long double eps = 1e-9;

struct pt{
    long long x, y;

    pt(const long long& x, const long long& y):x(x),y(y){}
    pt(){}

    pt operator +(const pt& p) const {
        return pt(x + p.x, y + p.y);
    }

    pt operator -(const pt& p) const {
        return pt(x - p.x, y - p.y);
    }

    bool operator <(const pt& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator ==(const pt& p) const {
        return x == p.x && y == p.y;
    }
};

long long scal(const pt& p, const pt& q){
    return p.x * q.x + p.y * q.y;
}

long long vec(const pt& p, const pt& q){
    return p.x * q.y - p.y * q.x;
}

bool cmp(const pt& p, const pt& q){
    auto qw = vec(p, q);
    return (qw > 0 || (qw == 0 && scal(p, p) < scal(q, q)));
}

int main(){

    int n = nxt();
    int p = nxt(), q = nxt();
    vector<pt> a(n);
    for (itn i = 0; i < n; i++){
        int x = nxt(), y = nxt();
        a[i] = pt(x, y);
    }

    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    n = a.size();

    if (n == 1){
        double t = max(1.0 * p / a[0].x, 1.0 * q / a[0].y);
        cout << setprecision(10) << fixed;
        cout << t << "\n";
        return 0;
    }

    pt ofs = a[0];
    for (int i = 0; i < n; i++)
        a[i] = a[i] - ofs;

    sort(a.begin() + 1, a.end(), &cmp);
    vector<pt> res(1, a[0]);
    res.push_back(a[1]);
    for (int i = 2; i < n; i++){
        while (res.size() > 2 && vec(res.back() - res[(itn)res.size() - 2], a[i] - res.back()) < 0)
            res.pop_back();
        res.push_back(a[i]);
    }

    n = res.size();
    for (int i = 0; i < n; i++)
        res[i] = res[i] + ofs;

    int mx = 0, my = 0;
    for (int i = 0; i < n; i++){
        if (res[i].x > mx)
            mx = res[i].x;
        if (res[i].y > my)
            my = res[i].y;
    }

    double ans = 1e9;
    pt pq(p, q);
    for (int i = 0; i < n; i++){
        ans = min(ans, max(1.0 * p / res[i].x, 1.0 * q / res[i].y));
        int nx = (i == n - 1) ? 0 : i + 1;
        if (vec(res[i], pq) == 0 || vec(res[nx], pq) == 0)
            continue;
        if ((vec(res[i], pq) > 0) ^ (vec(res[nx], pq) > 0)){
            auto q1 = abs(vec(res[i], pq));
            auto q2 = abs(vec(res[nx], pq));
            ans = min(ans, 1.0 * p / (res[i].x * q2 + res[nx].x * q1) * (q1 + q2));
        }
    }

    cout << setprecision(10) << fixed;
    cout << ans << "\n";

    return 0;
}