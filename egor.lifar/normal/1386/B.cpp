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
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using d = double;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;
const d eps = 1e-15;




__int128 gcd(__int128 a, __int128 b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}



__int128 mabs(__int128 a) {
	return (a >= 0 ? a : -a);
}



struct Ratio
{
	__int128 p, q;
	Ratio(){}
	Ratio(__int128 a, __int128 b) {
		p = a;
		q = b;
		auto d = mabs(gcd(p, q));
		if (d != 0) {
		p /= d;
		q /= d;
		}
		if (q < 0) {
			p = -p;
			q = -q;
		}
	}
};



void norm(Ratio &a) {
	auto d = mabs(gcd(a.p, a.q));
	if (d != 0) {
		a.p /= d;
		a.q /= d;
	}
	if (a.q < 0) {
		a.p = -a.p;
		a.q = -a.q;
	}
	if (a.p == 0 && a.q != 0) {
		a.q = 1;
	}
}


bool operator ==(const Ratio& a, const Ratio& b) {
	return a.p == b.p && a.q == b.q;
}


bool operator <(const Ratio& a, const Ratio& b) {
	return a.p * b.q < b.p * a.q;
} 



Ratio operator +(const Ratio& a, const Ratio& b) {
	Ratio c;
	c.q = a.q * b.q;
	c.p = a.p * b.q + b.p * a.q;
	norm(c);
	return c;
}



Ratio operator -(const Ratio& a, const Ratio& b) {
	Ratio c;
	c.q = a.q * b.q;
	c.p = a.p * b.q - b.p * a.q;
	norm(c);
	return c;
}



Ratio operator *(const Ratio& a, const Ratio& b) {
	Ratio c;
	c.p = a.p * b.p;
	c.q = a.q * b.q;
	norm(c);
	return c;
}



Ratio operator /(const Ratio& a, const Ratio& b) {
	Ratio c;
	c.p = a.p * b.q;
	c.q = a.q * b.p;
	norm(c);
	return c;
}



struct Point
{
	Ratio x, y;
	Point(){}
	Point(Ratio _x, Ratio _y) {
		x = _x;
		y = _y;
	}
};





bool operator ==(const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y;
}

bool operator <(const Point &a, const Point &b) {
	return mp(a.x, a.y) < mp(b.x, b.y);
}



Point operator -(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}


Point createPoint(ll a, ll b, ll c) {
	Point res(Ratio(a, a + b + c), Ratio(b, a + b + c));
	return res;
}


int n;
Point p[MAXN];
ll cnt1 = 0;
Point target;
map<Point, int> kek;





map<Point, int> cntr;



void print(Point pp) {
	cout << (ll)pp.x.p << '/' << (ll)pp.x.q << ' ' << (ll)pp.y.p << '/' << (ll)pp.y.q  << endl;
}







Ratio vec(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}


int check(Point a, Point b) {
	if (a == b) {
		return 0;
	}
	return vec(a, b).p < 0;
}


struct event
{
	Point a;
	event(){}
	event(Point _a) {
		a = _a;
	}
};




Ratio len(Point a) {
	return a.x * a.x + a.y * a.y;
}


bool operator ==(const event& a, const event& b) {	
	return a.a == b.a;
}



int getHalf(Point a) {
	return a.y.p > 0 || (a.y.p == 0 && a.x.p > 0); 
}



bool operator <(const event& a, const event& b) {
	int t = getHalf(a.a);
	int t1 = getHalf(b.a);
	if (t != t1) {
		return t > t1;          
	}
	if (a.a == b.a) {
		return false;
	}
	Ratio s = vec(a.a, b.a);   
	if (s.p == 0) {
		return len(a.a) < len(b.a); 
	} else {
		return s.p > 0;
	}
}
           

multiset<event> st;
int cntk = 0;



Point getRight(Point x) {
	auto f = st.upper_bound(event(x));
	if (f == st.end()) {
		f = st.begin();
	}
	return (*f).a;
}


Point getLeft(Point x) {
	auto f = st.lower_bound(event(x));
	if (f == st.begin()) {
		f = st.end();
	}
	f--;
	return (*f).a;
}





void norm(Point &a) {
	if (a.x.p == 0) {
		a.x.p = 0;
		a.x.q = 1;
		int c = (a.y.p > 0 ? 1: -1);
		a.y.p = c;
		a.y.q = 1;
	} else if (a.y.p == 0) {
		a.y.p = 0;
		a.y.q = 1;
		int c = (a.x.p > 0 ? 1: -1);
		a.x.p = c;
		a.x.q = 1;
	} else {
		//a.x.p / a.x.q
		//a.y.p / a.y.q
		a.x.p *= a.y.q;
		a.y.p *= a.x.q;
		a.x.q = 1;
		a.y.q = 1;
		auto d = mabs(gcd(a.x.p, a.y.p));
		a.x.p /= d;
		a.y.p /= d;
	}
}



map<Point, int> cntf;


void add(Point t) {
	if (t == target) {
		return;
	}
	t = t - target;
	norm(t);
	cntf[t]++;
	if (cntf[t] == 1) {
		auto t1 = event(t);
		if (sz(st) == 0) {
			st.insert(t1);
		} else {
			auto f = getLeft(t);
			auto f1 = getRight(t);
			cntk -= check(f, f1);
			cntk += check(f, t);
			cntk += check(t, f1);
			st.insert(t1);
		}
	}
}


void del(Point t) {
	if (t == target) {
		return;
	}
	t = t - target;
	norm(t);
	cntf[t]--;
	if (cntf[t] == 0) {
		auto t1 = event(t);
		st.erase(st.find(t1));
		if (st.empty()) {
			return;
		}
		auto f = getLeft(t);
		auto f1 = getRight(t);
		cntk += check(f, f1);
		cntk -= check(f, t);
		cntk -= check(t, f1);
	}
}





void proceedBich(int id) {
	Point x = p[id] - target;
	norm(x);
	Point x1 = x;
	x1.x.p *= -1;
	x1.y.p *= -1;
	cnt1 += cntr[x1];
	cntr[x]++;
}	


void proceedBich1(int id) {
	Point x = p[id] - target;
	norm(x);
	Point x1 = x;
	x1.x.p *= -1;
	x1.y.p *= -1;
	cntr[x]--;
	cnt1 -= cntr[x1];
}


void addPoint(int id) {
	kek[p[id]]++;
	proceedBich(id);
	add(p[id]);  
}


void delPoint(int id) {
	kek[p[id]]--;
	proceedBich1(id);
	del(p[id]);
}	


//  

int check() {
	if (kek[target]) {
		return 1;
	}
	if (cnt1) {
		return 2;
	}
	if (cntk == 0) {
		if (sz(st) >= 3) {
			return 3;
		}
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int ss, pp, gg;
	cin >> ss >> pp >> gg;
	target = createPoint(ss, pp, gg);	
	cin >> n;
	int uk = 0;
	for (int it = 0; it < n; it++) {
		char c;
		cin >> c;
		if (c == 'A') {
			int ph, pg, pd;
			cin >> ph >> pg >> pd;
			p[uk] = createPoint(ph, pg, pd);
			addPoint(uk);
			uk++;
		} else if (c == 'R') {
			int id;
			cin >> id;
			id--;
			delPoint(id);
		}
		cout << check() << '\n';
	}
}