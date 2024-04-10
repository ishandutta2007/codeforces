#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int ans;
struct vec{
	LL x, y;
	bool b;
}p[maxn];
vec operator- (const vec &a, const vec &b){
	return (vec){a.x - b.x, a.y - b.y, a.b};
}
vec operator- (const vec &a){
	return (vec){-a.x, -a.y};
}
vec operator* (const vec &a, const LL &b){
	return (vec){a.x * b, a.y * b};
}
LL operator* (const vec &a, const vec&b){
	return a.x * b.x + a.y * b.y;
}
int quadrant(const vec &a){
	if(a.y >= 0 and a.x > 0) return 1;
	if(a.x <= 0 and a.y > 0) return 2;
	if(a.y <= 0 and a.x < 0) return 3;
	if(a.x >= 0 and a.y < 0) return 4;
	return 0;
}
LL cross(const vec & a, const vec & b){
	return a.x * b.y - a.y * b.x;
}
bool operator< (const vec &a, const vec &b){
	int qa = quadrant(a), qb = quadrant(b);
	if(qa != qb) return qa < qb;
	LL c = cross(a, b);
	if(c != 0) return c > 0;
	return a * a < b * b;
}
void solve(vec *p, int N){
	vector<vec> v;
	for(int i = 1; i <= N; i += 1) v.push_back(p[i] - *p);
	sort(v.begin(), v.end());
	for(int i = 0; i < N; i += 1) v.push_back(v[i]);
	for(int i = 0; i < N; i += 1) if(not v[i].b){
		vec b = v[i] * 2;
		for(int j = i; j < N + i; j += 1) {
			if(cross(v[i], v[j]) < 0) break;
			if(cross(b - v[i], v[j] - v[i]) > 0){
				if(v[j].b) b = v[j];
				else ans += 1;
			}
		}
	}
}
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i += 1) scanf("%lld %lld", &p[i].x, &p[i].y);
	for(int i = N; i < N + M; i += 1){
		scanf("%lld %lld", &p[i].x, &p[i].y);
		p[i].b = true;
	}
	for(int i = 0; i < N; i += 1) solve(p + i, N + M - i - 1);
	printf("%d", ans);
}