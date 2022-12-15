#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1005;

ll gcd(ll a, ll b) {
  while(b) a %= b, swap(a, b);
	return a;
}
struct PT {
	ll x, y;
	PT(ll x = 0, ll y = 0) : x(x), y(y) {}
	PT operator + (const PT &p) { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) { return PT(x - p.x, y - p.y); }
	PT operator * (ll c) { return PT(x * c, y * c); }
	PT operator / (ll c) { return PT(x / c, y / c); }
	bool operator <(const PT &p) const {
		if((x - p.x) != 0) return x < p.x;
		return (y - p.y) != 0 && y < p.y;
	}
	bool operator ==(const PT &p) const {
		return (x - p.x) == 0 && (y - p.y) == 0;
	}
};

set<PT> intersect;
set<PT> temp;
int n;
ll ans = 0;
pair<PT, PT> pt[ms];

ll dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
ll dist2(PT p, PT q) { return dot(p - q, p - q); }

ll cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

ll signCross(PT p, PT q) { 
  ll temp = p.x * q.y - p.y * q.x; 
  if(temp != 0) return temp / abs(temp);
  return temp;
}

bool segmentsIntersect(PT a, PT b, PT c, PT d) {
    if(signCross(d - a, b - a) * signCross(c - a, b - a) > 0) return false;
    if(signCross(a - c, d - c) * signCross(b - c, d - c) > 0) return false;
    b = b - a; d = c - d; c = c - a;
    if(((b.x * cross(c, d)) % cross(b, d) == 0) && ((b.y * cross(c, d)) % cross(b, d) == 0)) return true;
    return false;
}

PT computeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    //assert(cross(b, d) != 0); // garante que as retas nao sao paralelas, remover pra evitar tle
    return a + b * cross(c, d) / cross(b, d);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> pt[i].first.x >> pt[i].first.y >> pt[i].second.x >> pt[i].second.y;
    //cout << abs(pt[i].first.x-pt[i].second.x) << ' '  << abs(pt[i].first.y-pt[i].second.y) << endl;
    ans += gcd(abs(pt[i].first.x-pt[i].second.x), abs(pt[i].first.y-pt[i].second.y)) + 1;
    //cout << gcd(2, 2) << endl;
    //cout << i << ' ' << ans << endl;
  }
  //cout << ans << endl;
  for(int i = 0; i < n; i++) {
    temp.clear();
    for(int j = 0; j < n; j++) {
      if(i != j && segmentsIntersect(pt[i].first, pt[i].second, pt[j].first, pt[j].second)) {
        intersect.insert(computeLineIntersection(pt[i].first, pt[i].second, pt[j].first, pt[j].second));
        temp.insert(computeLineIntersection(pt[i].first, pt[i].second, pt[j].first, pt[j].second));
      }
    }
    ans -= temp.size();
  }
  //for(auto p : intersect) cout << p.x << ' ' << p.y << endl;
  cout << ans + intersect.size() << endl;
  return 0;
}