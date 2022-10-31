#include <bits/stdc++.h>

#define EPS 1e-6
#define INF 1e9

using namespace std;
typedef double T;

int cmp(T x, T y = 0) {
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

struct point {
    T x, y;
    int id;

    point(T x = 0, T y = 0, int id = -1): x(x), y(y), id(id) {}

    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    point operator * (T c) { return point(x*c, y*c); }
    point operator / (T c) { return point(x/c, y/c); }
    bool operator < (const point b) const {
        return pair<T, T>(x, y) < pair<T, T>(b.x, b.y);
    }
};

inline T distPoints(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

inline T escalar(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

inline T vetorial(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(point p, point q, point o) {
	return cmp(vetorial(p - o, q - o));
}

T angle(point p, point q, point o) {
	point u = p - q, v = o - q;
	return atan2(vetorial(u, v), escalar(u, v));
}

point pivot;
bool polar_cmp(point a , point b) {
    T cross = vetorial(a - pivot, b - pivot);
    return cmp(cross) == 1 || (cmp(cross) == 0 && cmp(distPoints(pivot - a), distPoints(pivot - b)) == -1);
}

vector<point> convex_hull(vector<point> p, bool repeat_last = false) {
    if(p.size() <= 2) return p;

    int pi = 0;
    for(int i = 1; i < p.size(); i++)
        if(p[i] < p[pi]) pi = i;

    swap(p[0], p[pi]); pivot = p[0];
    sort(p.begin()+1, p.end(), polar_cmp);

    vector<point> s;
    s.push_back(p.back()); s.push_back(p[0]); s.push_back(p[1]);

    for(int i = 2; i < p.size();) {
        int j = s.size()-1;
        if(s.size() == 2 || ccw(s[j], p[i], s[j-1]) == 1) s.push_back(p[i++]);
        else s.pop_back();
    }
    if(!repeat_last) s.pop_back();
    return s;
}

int n;
vector<point> p, ans, ch;
char s[3010];

bool use(point po) {
    for(int i = 0; i < p.size(); i++) {
        if(p[i].id == po.id ) {
            p.erase(p.begin() + i);
            ans.push_back(po);
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.push_back(point(x, y, i));
    }
    ch = convex_hull(p);
    scanf("%s", s);

    use(ch[1]);
    if(s[0] == 'L') use(ch[2]);
    else use(ch[0]);

    for(int i = 0; i + 1 < n; i++) {
        point tmp = p.back();
        if(s[i] == 'L') {
            if(s[i + 1] == 'R') { // menor negativo
                for(point po : p)
                    if(angle(ans[i], ans[i+1], po) > angle(ans[i], ans[i+1], tmp))
                        tmp = po;
            } else { // maior abs negativo
                for(point po : p)
                    if(angle(ans[i], ans[i+1], po) < angle(ans[i], ans[i+1], tmp))
                        tmp = po;
            }
        } else {
            if(s[i + 1] == 'L') { // menor positivo
                for(point po : p)
                    if(angle(ans[i], ans[i+1], po) < angle(ans[i], ans[i+1], tmp))
                        tmp = po;
            } else { // maior positivo
                for(point po : p)
                    if(angle(ans[i], ans[i+1], po) > angle(ans[i], ans[i+1], tmp))
                        tmp = po;
            }
        }
        use(tmp);
    }
    use(p.back());

    for(point po : ans) printf("%d ", po.id);
    return 0;
}