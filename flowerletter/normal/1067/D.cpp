#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
#define double long double
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
const int maxn = 1e5;
const double eps = 1e-10;
const int mxlg = 45;
ll n, m, t;
double mx;
struct F {
	double k, b;
}b[maxn + 5];
struct Node {
	double a, b, p;
	F x;
}a[maxn + 5];
inline int sgn(double x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
double inter(int i, int j) {
	return (b[j].b - b[i].b) / (b[i].k - b[j].k);
}
struct Mat {
	double a[3][3];
	double* operator [] (int x) {return a[x];}
	Mat() {rep(i, 0, 2) rep(j, 0, 2) a[i][j] = 0;}
	Mat(F x) {
		a[0][0] = a[0][1] = a[1][1] = 1, a[1][0] = a[2][0] = a[2][1] = 0;
		a[0][2] = x.b, a[1][2] = x.k * mx, a[2][2] = 1 - x.k;
	}
	friend Mat operator * (Mat x, Mat y) {
		Mat z;
		rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2) z[i][j] += x[i][k] * y[k][j];
		return z;
	}
	void debug() {
		rep(i, 0, 2) rep(j, 0, 2) cout << a[i][j] << " \n"[j == 2];
	}
}f[mxlg + 5];
Mat fpw(Mat a, ll b) {
	Mat ans; ans[0][0] = ans[1][1] = ans[2][2] = 1;
	for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans * a;
	return ans;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	scanf("%lld%lld", &n, &t);
	rep(i, 1, n) scanf("%Lf%Lf%Lf", &a[i].a, &a[i].b, &a[i].p), a[i].x = {a[i].p, a[i].p * a[i].a}, chkmx(mx, a[i].p * a[i].b);
	sort(a + 1, a + n + 1, [&] (Node x, Node y) {return x.p < y.p;});
	for(int l = 1, r; l <= n; l = r) {
		r = l;
		int id = l;
		while(r <= n && !sgn(a[r].p - a[l].p)) id = a[r].x.b > a[id].x.b ? r : id,  r ++;
		b[++ m] = a[id].x;
	}
	deque<int> q;
	rep(i, 1, m) {
		while(sz(q) > 1 && sgn(inter(q[sz(q) - 2], q[sz(q) - 1]) - inter(q[sz(q) - 2], i)) >= 0) q.pop_back();
		q.push_back(i);
	}
//	for(auto x : q) printf("%.10Lf %.10Lf\n", 1 - b[x].k, b[x].b); 
	Mat cur;
	cur[0][0] = 1;
	rep(i, 0, sz(q) - 2) {
		f[0] = Mat(b[q[i]]);
		double end = inter(q[i], q[i + 1]);
		rep(i, 1, mxlg) f[i] = f[i - 1] * f[i - 1];
//		cout << end << '\n'; 
		if(sgn(mx * cur[0][1] - cur[0][2] - end) >= 0) continue;
		Mat lst = cur;
		per(i, mxlg, 0) {
			Mat nxt = cur * f[i];
			if(sgn(mx * nxt[0][1] - nxt[0][2] - end) <= 0) cur = nxt;
//			if(!i) {
//				printf("%.10Lf\n", mx * nxt[0][1] - nxt[0][2]);
//			}
		}
		cur = cur * f[0];
		if(cur[0][1] >= t) {
			printf("%.10Lf\n", (lst * fpw(f[0], t - lst[0][1]))[0][2]);
			return 0;
		}
//		cout << cur[0][1] << '\n';
	}
//	cout << "qwq\n";
//	rep(i, 0, 10) {
//		Mat nxt = cur * fpw(Mat(b[1]), i) * fpw(Mat(b[2]), 10 - i);
//		printf("%.10Lf\n", nxt[0][2]); 
//	}
	printf("%.10Lf\n", (cur * fpw(Mat(b[q[sz(q) - 1]]), t - cur[0][1]))[0][2]);
	return 0;
}