#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> pt;

int main() {
ld px, py, vx, vy, a, b, c, d; cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

pt p(px, py);
pt v(vx, vy);
v /= abs(v);

vector<pt> res;
res.emplace_back(b, 0);
res.emplace_back(0, a / 2);
res.emplace_back(0, c / 2);
res.emplace_back(-d, c / 2);
res.emplace_back(-d, -c / 2);
res.emplace_back(0, -c / 2);
res.emplace_back(0, -a/2);


for(pt vert : res) {
vert *= v;
vert += p;
cout << fixed << setprecision(10) << vert.real() << ' ';
cout << fixed << setprecision(10) << vert.imag() << '\n';
}
}