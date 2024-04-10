#include<bits/stdc++.h>
#define maxn 300
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
struct point{
	LL x, y;
}p[maxn];
LL cross(const point &a, const point &b){
	return a.x * b.y - a.y * b.x;
}
LL f[maxn][maxn];
int main(){
	int T = 1;
	//scanf("%d", &T);
	while(T --){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i += 1) scanf("%lld %lld", &p[i].x, &p[i].y);
		LL rot = 0;
		for(int i = 0; i < n; i += 1) rot += cross(p[i], p[(i + 1) % n]);
		if(rot < 0) reverse(p, p + n);
		for(int i = 0; i < n; i += 1) fill(f[i], f[i] + n, 0LL);
		for(int i = 0; i + 1 < n; i += 1) f[i][i + 1] = 1;
		for(int i = n - 3; i >= 0; i -= 1)
			for(int j = i + 2; j < n; j += 1)
				for(int k = i + 1; k < j; k += 1)
					if (cross(p[i], p[j]) + cross(p[j], p[k]) < cross(p[i], p[k]))
						f[i][j] = (f[i][j] + f[i][k] * f[k][j]) % mod;
		printf("%lld\n", f[0][n - 1]);
	}
}