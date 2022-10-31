#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;



int xx, yy, x, y;




int main(){
 //   ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> x >> y >> xx >> yy;
	if (x + y <= max(xx, yy)) cout << "Polycarp\n";
	else if (yy < y || xx < x) cout << "Vasiliy\n";
	else cout << "Polycarp\n";
}