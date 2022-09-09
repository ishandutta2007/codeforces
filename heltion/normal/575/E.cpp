#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
constexpr int maxn = 1000000;
struct P{
	LL x, y;
	P(LL x = 0, LL y = 0): x(x), y(y){}
}p[maxn * 8], h[maxn * 8];
P operator - (const P& A, const P& B){return P(A.x - B.x, A.y - B.y);}
LL operator * (const P& A,const P& B){return A.x * B.x + A.y * B.y;}
LL dis(const P& A){return A * A;}
LL cross(const P& A, const P& B){return A.x * B.y - A.y * B.x;}
int convex_hull(P *p , int n, P *h){
	sort(p, p + n, [](const P& a, const P& b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	n = unique(p, p + n, [](const P& a, const P& b){
		return a.x == b.x && a.y == b.y;
	}) - p;
	int m = 0;
	for(int i = 0; i < n; i += 1){
		while(m > 1 && cross(h[m - 1] - h[m - 2], p[i] - h[m - 2]) <= 0) m -= 1;
		h[m ++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; i -= 1){
		while(m > k && cross(h[m - 1] - h[m - 2], p[i] - h[m - 2]) <= 0) m -= 1;
		h[m ++] = p[i];
	}
	return m -= 1;
}
int main(){
	ios::sync_with_stdio(false);
	int n, m = 0, X = 100000;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		int x, y, v;
		cin >> x >> y >> v;
		if(x - v >= 0) p[m++] = P(x - v, y);
		else p[m++] = P(0, min(y + v - x, X)), p[m++] = P(0, max(y - v + x, 0));
		if(x + v <= X) p[m++] = P(x + v, y);
		else p[m++] = P(X, min(y + x + v - X, X)), p[m++] = P(X, max(y - x - v + X, 0));
		if(y - v >= 0) p[m++] = P(x, y - v);
		else p[m++] = P(min(x + v - y, X), 0), p[m++] = P(max(x - v + y, 0), 0);
		if(y + v <= X) p[m++] = P(x, y + v);
		else p[m++] = P(min(x + y + v - X, X), X), p[m++] = P(max(x - y - v + X, 0), X);
	}
	n = convex_hull(p, m, h);
	h[n] = h[0], h[n + 1] = h[1];
	int ansi = 0;
	LD ans = 0;
	for(int i = 0; i < n; i += 1){
		//cout << h[i].x << " " << h[i].y << "\n";
		LD pans = (LD)dis(h[i + 1] - h[i]) * dis(h[i + 2] - h[i]) * dis(h[i + 2] - h[i + 1])
			/ cross(h[i + 1] - h[i], h[i + 2] - h[i]) / cross(h[i + 1] - h[i], h[i + 2] - h[i]);
		if(pans > ans){
			ans = pans;
			ansi = i;
		}
	}
	for(int i = ansi; i < ansi + 3; i += 1)
		cout << h[i].x << " " << h[i].y << "\n";
}