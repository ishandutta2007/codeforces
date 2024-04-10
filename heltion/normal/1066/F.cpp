#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("-1"); exit(0);}

#define maxn 240000
struct point{
	LL x, y;
	bool operator < (const point &rhs){
		if(x != rhs.x) return x < rhs.x;
		return y > rhs.y;
	}
};
LL dis(const point &a, const point &b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}
vector<point> G[maxn];
LL x[maxn], y[maxn];
LL L[maxn], m;
point P[2][maxn];
LL f[2][maxn];
map<LL, int> ma;
int main(){
	int n = read();
	for(int i = 0; i < n; i += 1){
		x[i] = read();
		y[i] = read();
		L[i] = max(x[i], y[i]);
	}
	sort(L, L + n);
	m = unique(L, L + n) - L;
	for(int i = 0; i < m; i += 1) ma[L[i]] = i;
	for(int i = 0; i < n; i += 1)
		G[ma[max(x[i], y[i])]].push_back((point){x[i], y[i]});
	for(int i = 0; i < m; i += 1){
		P[0][i] = *min_element(G[i].begin(), G[i].end());
		P[1][i] = *max_element(G[i].begin(), G[i].end());	
		//printf("i = %d, %lld, %lld, %lld, %lld\n",
		//	i, P[0][i].x, P[0][i].y, P[1][i].x, P[1][i].y);
	}
	for(int i = 0; i < m; i += 1){
		if(i == 0){
			f[0][0] = dis(P[1][0], (point){0LL, 0LL}) + dis(P[1][0], P[0][0]);
			f[1][0] = dis(P[0][0], (point){0LL, 0LL}) + dis(P[1][0], P[0][0]);
		}
		else{
			f[0][i] = f[1][i] = 1E18;
			f[0][i] = min(f[0][i], f[0][i - 1] + dis(P[0][i - 1],
				P[1][i]) + dis(P[1][i], P[0][i]));
				
			f[0][i] = min(f[0][i], f[1][i - 1] + dis(P[1][i - 1],
				P[1][i]) + dis(P[1][i], P[0][i]));
				
			f[1][i] = min(f[1][i], f[0][i - 1] + dis(P[0][i - 1],
				P[0][i]) + dis(P[1][i], P[0][i]));
				
			f[1][i] = min(f[1][i], f[1][i - 1] + dis(P[1][i - 1],
				P[0][i]) + dis(P[1][i], P[0][i]));
		}
	}
	//for(int i = 0; i < m; i += 1){
	//	printf("i = %d, %lld, %lld\n", i, f[0][i], f[1][i]);
	//}
	printf("%lld", min(f[0][m - 1], f[1][m - 1]));
}