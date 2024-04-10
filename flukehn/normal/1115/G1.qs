#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
typedef double ld;
const int N=8e5+10;
const ld eps=1e-9,eps2=1e-5;

struct Point {
	ld x, y;
}p[N];

typedef Point P;

ld Length(P u){return u.x*u.x+u.y*u.y;}
P operator-(P u, P v){ return (P){u.x - v.x, u.y - v.y};}
P operator+(P u, P v) {return (P){u.x + v.x, u.y + v.y};}
P operator*(P u, ld x) {return (P){u.x * x, u.y * x};}
int n, m;
P vec[N],dir[N];
ld len[N];
struct func{
	ld tl,tr,a,b,c;
}F[N];

struct Ev{
	ld t;
	int w;
	bool operator<(const Ev&B){
		return fabs(B.t-t)<eps?w<B.w:t<B.t;
	}
};

int cnt;

bool check(ld lim) {
	int p = 0;
	static Ev A[N];
	For(i,1,cnt) {
		ld a=F[i].a,b=F[i].b,c=F[i].c-lim,dur=F[i].tr-F[i].tl;
		//assert(a > -eps);
		if (fabs(a)<eps&&fabs(b)<eps) {
			if(c<eps) A[++p] = (Ev){F[i].tl, 1}, A[++p] = (Ev){F[i].tr, -1};
		} else if (fabs(a) < eps) {
			ld rt = -c / b;
			if (b < 0 && rt > 0) A[++p] = (Ev){F[i].tl, 1}, A[++p] = (Ev){F[i].tl + min(rt, dur), -1};
			if (b > 0 && rt < dur) A[++p] = (Ev){max(rt, 0.0) + F[i].tl, 1}, A[++p] = (Ev){F[i].tr, -1};
		} else {
			ld det = b * b - 4 * a * c;
			if (det < 0) continue;
			det = sqrt(det);
			ld x1 = (-b - det) / (2 * a), x2 = (-b + det) / (2 * a);
			if (x1 > dur || x2 < 0) continue;
			x1 = max(x1, 0.0), x2 = min(x2, dur);
			A[++p] = (Ev){F[i].tl + x1, 1}, A[++p] = (Ev){F[i].tl + x2, -1};
		}
	}
	sort(A + 1, A + p + 1);
	int cur = 0;
	For(i, 1, p) {
		cur += A[i].w;
		if (cur == m) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
#endif
	scanf("%d%d", &n, &m);
	For(i,1,n) scanf("%lf%lf", &p[i].x, &p[i].y);
	ld C = 0;
	For(i, 1, n) {
		len[i] = sqrt(Length(vec[i] = p[i % n + 1] - p[i])), C += len[i];
		dir[i] = vec[i] * (1.0 / len[i]);
	}

	int pl = 1, pr = 1;
	ld d = C / m, remd = d, cur = 0;
	int id = 1;
	while (len[pr] < remd + eps) remd -= len[pr], ++pr;
	Point A = p[1], B = p[pr] + dir[pr] * remd;
	ld rema = len[1], remb = len[pr] - remd;
	//cout<<rema<<" "<<remb<<endl;
	while (C - cur > eps2) {
		ld t = min(rema, min(remb, id * d - cur));
		P st = B - A, delt = dir[pr] - dir[pl];
		ld a = Length(delt), b = 2 * (delt.x * st.x + delt.y * st.y), c = Length(st);
		F[++cnt].tl = cur - (id - 1) * d, F[cnt].tr = F[cnt].tl + t;
		F[cnt].a = a, F[cnt].b = b, F[cnt].c = c;
		//cout<<cnt<<" "<<cur<<" "<<a<<" "<<b<<" "<<c<<" "<<t<<endl;
		cur += t;
		if (id * d - cur < eps2) ++id;
		A = A + dir[pl] * t, B = B + dir[pr] * t;
		if (rema - t < eps) pl = pl % n + 1, rema = len[pl]; else rema -= t;
		if (remb - t < eps) pr = pr % n + 1, remb = len[pr]; else remb -= t;
	}

	ld L = 0, R = d;
	while (R - L > eps) {
		ld mid = (L + R) / 2;
		if (check(mid * mid)) R = mid;
		else L = mid;
	}
	printf("%.8lf\n", L);

	return 0;
}