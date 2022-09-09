#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
constexpr int maxn = 120000;
int sgn(LL x){return x ? x < 0 ? -1 : 1 : 0;}
struct P{
	LL x, y, z;
	P(LL x = 0, LL y = 0, LL z = 0): x(x), y(y), z(z){};
}p[2][maxn], n[2];
LL operator * (P A, P B){return A.x * B.x + A.y * B.y + A.z * B.z;}
P operator - (P A, P B){return P(A.x - B.x, A.y - B.y, A.z - B.z);}
P cross(P A, P B){return P(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);}
int m[2], mix[maxn];
int main(){
	ios::sync_with_stdio(false);
	for(int t = 0; t < 2; t += 1){
		cin >> m[t];
		for(int i = 0; i < m[t]; i += 1) cin >> p[t][i].x >> p[t][i].y >> p[t][i].z;
		p[t][m[t]] = p[t][0];
		n[t] = cross(p[t][1] - p[t][0], p[t][2] - p[t][0]);
	}
	P X = cross(n[0], n[1]);
	if(X * X == 0){
		cout << "NO";
		return 0;
	}
	vector<pair<LD, pair<int, int>>> v;
	for(int t = 0; t < 2; t += 1){
		for(int i = 0; i <= m[t]; i += 1) mix[i] = sgn((p[t][i] - p[t ^ 1][0]) * n[t ^ 1]);
		for(int i = 0; i < m[t]; i += 1){
			if(mix[i] == mix[i + 1]) continue;
			LD k = (LD)(n[t ^ 1] * (p[t][i] - p[t ^ 1][0])) / (n[t ^ 1] * (p[t][i] - p[t][i + 1]));
			LD Y = (p[t][i] * X) + (p[t][i + 1] - p[t][i]) * X * k;
			v.push_back(make_pair(Y, make_pair(t, mix[i] - mix[i + 1])));
		}
	}
	sort(v.begin(), v.end());
	int sgn = 0, io = 0;
	for(auto p : v){
		if(p.second.first) sgn += io * p.second.second;
		else io += p.second.second;
	}
	cout << (sgn == 0 ? "NO" : "YES");
}