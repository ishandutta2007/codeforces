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

struct pt{
	long long x, y;
	itn num;

	pt(long long x, long long y):x(x),y(y){}
	pt(){x = y = 0;}

	pt operator -(const pt& p) const {
		return pt(x - p.x, y - p.y);
	}

	void in(){
		x = nxt();
		y = nxt();
	}
};

long long vec(const pt& p, const pt& q){
	return p.x * q.y - p.y * q.x;
}

long long S(const pt& p, const pt& q, const pt& r){
	return abs(vec(q - p, r - p));
}

inline bool inside(const vector<pt>& a, const pt& p){
	return S(a[0], a[1], a[2]) - S(a[0], a[1], p) == S(a[0], a[2], p) + S(a[2], a[1], p);
}

int main(){

	int n = nxt();

	vector<pt> b(n);
	for (int i = 0; i < n; i++){
		b[i].num = i;
		b[i].in();
	}
	int i = 2;
	while (!S(b[0], b[1], b[i]))
		i++;
	swap(b[2], b[i]);

	vector<pt> a(3);
	for (int i = 0; i < n; i++){
		if (i < 3){
			a[i] = b[i];
		} else {
			pt p;
			p = b[i];
			if (inside(a, p)){
				if (!vec(a[0] - p, a[1] - p))
					a[1] = p;
				else if (!vec(a[0] - p, a[2] - p))
					a[2] = p;
				else if (!vec(a[2] - p, a[1] - p))
					a[1] = p;
				else
					a[2] = p;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		cout << a[i].num + 1 << " ";
	cout << "\n";

	return 0;
}