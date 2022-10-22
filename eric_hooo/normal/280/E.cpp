#include <bits/stdc++.h>
#define double long double
using namespace std;

struct Block {
	double l, r;
	double a, b, c;
	Block() {}
	Block(double L, double R, double A, double B, double C) {l = L, r = R, a = A, b = B, c = C;}
	double GetVal(double x) const {return a * x * x + b * x + c;}
	double GetDiff() const {return 2 * a * l + b;}
	void Move(double d) {
		l += d, r += d;
		c += a * d * d - b * d;
		b -= 2 * a * d;
	}
};

Block a[12010];
int lb, rb, pos;
double Q, A, B;
vector <double> seq;
double liml[60010], limr[60010];
double input[60010];
double px[60010];

void Flush() {
	while (lb < rb && a[lb].r < 0) lb++, pos = max(pos, lb);
	a[lb].l = max(a[lb].l, (double)1);
	while (lb < rb && a[rb - 1].l > Q) rb--, pos = min(pos, rb - 1);
	a[rb - 1].r = min(a[rb - 1].r, Q);
}

int main() {
	int n; cin >> n >> Q >> A >> B;
	lb = rb = 0, a[rb++] = Block(-1e18, 1e18, 0, 0, 0), pos = 0;
	for (int it = 1; it <= n; it++) {
		double x; cin >> x; input[it - 1] = x;
		for (int j = lb; j < pos; j++) a[j].Move(A);
		for (int j = rb; j > pos; j--) a[j] = a[j - 1], a[j].Move(B);
		rb++;
		double minj = a[pos].GetVal(a[pos].l);
		a[pos].r = a[pos].l + B, a[pos].l += A, a[pos].a = a[pos].b = 0, a[pos].c = minj;
		Flush();
		liml[it] = a[pos].l, limr[it] = a[pos].r;
		for (int i = lb; i < rb; i++) a[i].a++, a[i].b -= 2 * x, a[i].c += x * x;
		while (pos + 1 < rb && a[pos + 1].GetDiff() <= 0) pos++;
		while (pos > lb && a[pos].GetDiff() > 0) pos--;
		if (a[pos].GetDiff() < 0) {
			double mid = -a[pos].b / a[pos].a / 2;
			if (a[pos].l < mid && mid < a[pos].r) {
				for (int i = rb; i > pos; i--) a[i] = a[i - 1];
				a[pos].r = mid, a[pos + 1].l = mid, pos++, rb++;
			} else {
				if (pos + 1 < rb) pos++;
				else {
					a[rb] = a[rb - 1], a[rb].l = a[rb].r, pos++, rb++;
				}
			}
		}
		px[it] = a[pos].l;
	}
	cout << fixed << setprecision(6);
	double cur = a[pos].l;
	for (int it = n; it >= 2; it--) {
		seq.push_back(cur);
		if (px[it - 1] > cur - A) cur -= A;
		else if (px[it - 1] < cur - B) cur -= B;
		else cur = px[it - 1];
	}
	seq.push_back(cur);
	reverse(seq.begin(), seq.end());
	double ans = 0;
	for (int i = 0; i < seq.size(); i++) ans += (seq[i] - input[i]) * (seq[i] - input[i]);
	for (int i = 0; i < seq.size(); i++) cout << seq[i] << " "; cout << endl;
	cout << a[pos].GetVal(a[pos].l) << endl;
	return 0;
}