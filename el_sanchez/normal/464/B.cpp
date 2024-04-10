#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 1111;
    
struct pt {
	ll x, y, z;
	
	pt(){};
	
	pt(ll _x, ll _y, ll _z): x(_x), y(_y), z(_z) {};
};

pt operator-(pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y, a.z - b.z); 
}

pt operator+(pt a, pt b) {
	return pt(a.x + b.x, a.y + b.y, a.z + b.z); 
}

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(pt a, pt b) {
	return !(a == b);
}

ll operator*(pt a, pt b) {
	return a.x * b.x + a.y * b.y + a.z * b.z; 
}

ll len(pt a) {
	return a.x * a.x + a.y * a.y + a.z * a.z; 
}

bool f;
int id[8], used[8], used2[3];
pt p[8];    
pair<ll, int> lens[7];

int iter = 0;

bool check() {
    //0 - start
    for (int i = 1; i < 8; i++)
    	lens[i - 1] = mp(len(p[0] - p[i]), i);
    sort(lens, lens + 7);

    ll len1 = lens[0].X;
    if (len1 == 0)
    	return 0;
    if (lens[0].X != len1 || lens[1].X != len1 || lens[2].X != len1)
    	return 0;
    		
	if (lens[3].X != len1 * 2 || lens[4].X != len1 * 2 || lens[5].X != len1 * 2)
    	return 0; 		
	
   	if (lens[6].X != len1 * 3)
   		return 0;

   	if ((p[lens[0].Y] - p[0]) * (p[lens[1].Y] - p[0]) != 0)
   		return 0;	
   	if ((p[lens[1].Y] - p[0]) * (p[lens[2].Y] - p[0]) != 0)
   		return 0;	
   	if ((p[lens[0].Y] - p[0]) * (p[lens[2].Y] - p[0]) != 0)
   		return 0;	
   		
   	forn(i, 8)
   		used[i] = 0;
   	forn(i, 3)
   		used2[i] = 0;

   	for (int i = 3; i <= 5; i++) {
   		if (p[0] + (p[lens[0].Y] - p[0]) + (p[lens[1].Y] - p[0]) == p[lens[i].Y])
   			used[i]++, used2[0]++;
   		if (p[0] + (p[lens[1].Y] - p[0]) + (p[lens[2].Y] - p[0]) == p[lens[i].Y])
   			used[i]++, used2[1]++;
   		if (p[0] + (p[lens[0].Y] - p[0]) + (p[lens[2].Y] - p[0]) == p[lens[i].Y])
   			used[i]++, used2[2]++;
   		if (used[i] != 1)
   			return 0;	
   	}
   	
   	if (used2[0] != 1 || used2[1] != 1 || used2[2] != 1)
   		return 0;
   		
   	if (p[0] + (p[lens[0].Y] - p[0]) + (p[lens[1].Y] - p[0]) + (p[lens[2].Y] - p[0]) != p[lens[6].Y])
   		return 0;
   		 
	return 1;
}

void go(int v) {
	if (v == 8) {
		/*
		if (iter % 10000 == 0) {
				forn(i, 8)
				cout << p[i].x << ' ' << p[i].y << ' ' << p[i].z << '\n';
			cout << '\n';
		}
		iter++;
		*/
		if (check()) {
			f = 1;
		}
		return;
	}
	
	int id[3];
	ll tmp[3];
	
	forn(i, 3)
		id[i] = i;
	tmp[0] = p[v].x;
	tmp[1] = p[v].y;
	tmp[2] = p[v].z;   	

	//cerr << v << endl;
		
	forn(i, 6) {
		go(v + 1);

		if (f)
			return;

		next_permutation(id, id + 3);
		p[v].x = tmp[id[0]];
		p[v].y = tmp[id[1]];
		p[v].z = tmp[id[2]]; 			
	}
}

int main() {

	forn(i, 8)
		cin >> p[i].x >> p[i].y >> p[i].z;
	
	f = 0;
	go(0);

	if (f) {
		cout << "YES\n";
		forn(i, 8)
			cout << p[i].x << ' ' << p[i].y << ' ' << p[i].z << '\n';
	} else
		cout << "NO";
		
	return 0;
}