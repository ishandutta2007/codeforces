#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;
const int INF = 1000000000;
int n;
struct rect{
	int x1, y1, x2, y2;
	rect(): x1(-INF), y1(-INF), x2(INF), y2(INF){}
	rect(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2){}
}r[20][maxn];
rect operator & (const rect &a, const rect &b){
	return rect(max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2));
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1)
		scanf("%d %d %d %d", &r[0][i].x1, &r[0][i].y1, &r[0][i].x2, &r[0][i].y2);
	for(int k = 1; k < 20; k += 1)
		for(int j = 1; j + (1 << k) - 1 <= n; j += 1)
			r[k][j] = r[k - 1][j] & r[k - 1][j + (1 << k - 1)];
	for(int i = 1; i <= n; i += 1){
		rect ans;
		if(i > 1){
			int L = 1, R = i - 1;
			for(int k = 0; 1 << k <= R - L + 1; k += 1){
				ans = ans & r[k][L];
				ans = ans & r[k][R - (1 << k) + 1];
			}
		}
		if(i < n){
			int L = i + 1, R = n;
			for(int k = 0; 1 << k <= R - L + 1; k += 1){
				ans = ans & r[k][L];
				ans = ans & r[k][R - (1 << k) + 1];
			}
		}
		//printf("%d %d %d %d\n", ans.x1, ans.y1, ans.y2, ans.y2);
		if(ans.x1 <= ans.x2 && ans.y1 <= ans.y2){
			printf("%d %d", ans.x1, ans.y1);
			break;
		}
	}
}