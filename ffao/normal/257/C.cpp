    #include<bits/stdc++.h>
    using namespace std;
     
    #ifdef LOCAL
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #else
    #define debug(...) ;
    #endif
     
     
    typedef long long ll;
    typedef long double ld;
    #define rep(i, start, end) for(int i = start; i < end; ++i)
    #define sz(x) (int)((x).size())
    #define pb push_back
    #define all(x) x.begin(), x.end()
    #define clr(d, v) memset(d, v, sizeof(d))
    #define pii pair<int, int>
    #define X first
    #define Y second
    //#define debug(x) cerr << #x << " : " << (x) << " "
    const double PI = 3.14159265358979323846;
    const double eps = (1e-9);
    enum {LESS, EQUAL, GREATER};
    int dcmp(ld x, ld y)
    {
        if (fabs(x - y) <= eps)
            return EQUAL;
        return x > y ? GREATER : LESS;
    }
     
    long double to_deg(long double angle)
    {
        return angle * 180.0 / PI;
    }
    int sign(int x)
    {
        if (x == 0)
            return 0;
        return x > 0 ? 1 : -1;
    }
    int n;
    ld maxAngle;
    struct Point{
        int x, y;
        void normalize()
        {
            if (x == 0)
                y = sign(y);
            else if (y == 0)
                x = sign(x);
            else
            {
                int d = __gcd(abs(x), abs(y));
                x /= d;
                y /= d;
            }
        }
        int getQuad() const {
            if (x >= 0) {
                if (y >= 0) return 0;
                return 3;
            }
            if (y >= 0) return 1;
            return 2;
        }
        int cross (Point other) const{
            return x * other.y - y * other.x;
        }
        int dot(Point other) const {
            return x * other.x + y * other.y;
        }
        bool operator<(const Point &other) const {
            int q1 = getQuad(), q2 = other.getQuad();
            if (q1 != q2) {
                return q1 < q2;
            }
            auto c = cross(other);
            if (c == 0) { // both on same ray, return the closer to the origin
                return len() < other.len();
            }
            return c > 0;
        }
        bool operator == (const Point &other) const{
            return !((*this) < other) && !(other < (*this));
        }
        ld len() const{
            return sqrt(x * x + y * y);
        }
        ld getAngleTo(Point other) const{
            ld ret = atan2(cross(other), dot(other));
            if (ret < 0)
                ret += 2 * PI;
            return to_deg(ret);
        }
        long double getDegrees() const{
            long double ret = atan2(y, x);
            if (ret < 0)
                ret += 2 * PI;
            return to_deg(ret);
        }
        friend istream& operator>>(istream& in, Point &p) {
            in >> p.x >> p.y;
            return in;
        }
        friend ostream& operator<<(ostream& out, const Point &p){
            cout << p.x << " " << p.y;
            return out;
        }
    };
    bool cmp(Point p1, Point p2)
    {
        return p1.getDegrees() < p2.getDegrees();
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    //    freopen("AC.txt", "w", stdout);
    #endif
        cin >> n;
        set<Point> s;
        vector<Point> pts(n);
        rep(i,0,n)
        {
            cin >> pts[i];
            s.insert(pts[i]);
        }
        pts.clear();
        pts.insert(pts.begin(), s.begin(), s.end());
    //    sort(all(pts), cmp);
    //    pts.resize(unique(all(pts)) - pts.begin());
    //    rep(i,0,n - 1)
    //    {
    //        int j = (i + 1);
    //        if (pts[i].cross(pts[i + 1]) < 0)
    //        {
    //            cout << pts[i].getQuad() << " " << pts[j].getQuad() << endl;
    //            cout << pts[i].cross(pts[j]) << endl;
    //            cout << pts[j].cross(pts[i]) << endl;
    //            cout << pts[i] << endl << pts[j] << endl;
    //            cout << pts[j].getDegrees() - pts[i].getDegrees() << endl;
    //            cout << pts[i].getAngleTo(pts[j]) << endl;
    //            exit(13);
    //
    //        }
    //    }
        if (sz(pts) == 1)
        {
            cout << 0 << '\n';
            return 0 ;
        }
        ld ans = 1e30;
        cout << fixed;
        rep(i,0,n - 1)
        {
            int j = (i + 1);
            if (dcmp(pts[j].getDegrees() - pts[i].getDegrees(), pts[i].getAngleTo(pts[j])) != EQUAL)
            {
                cout << pts[i].getQuad() << " " << pts[j].getQuad() << endl;
                cout << pts[i].cross(pts[j]) << endl;
                cout << pts[j].cross(pts[i]) << endl;
                cout << pts[i] << endl << pts[j] << endl;
                cout << pts[j].getDegrees() - pts[i].getDegrees() << endl;
                cout << pts[i].getAngleTo(pts[j]) << endl;
                exit(12);
            }
            ans = min(ans,360 - pts[j].getDegrees() + pts[i].getDegrees());
        }
        ans = min(ans, pts.back().getDegrees() - pts[0].getDegrees());
    //    if (n == 100000)
    //        cout << fixed << maxAngle << endl;
        cout << fixed << setprecision(12) << ans << '\n';
     
    }