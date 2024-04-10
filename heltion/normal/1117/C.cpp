#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int x[2], y[2];
#define maxn 120000
char s[maxn];
LL sx[maxn], sy[maxn];
	int n;
bool pd(LL M){
	LL xx = x[1] - x[0], yy = y[1] - y[0];
	LL ssx = M / n * sx[n] + sx[M % n], ssy = M / n * sy[n] + sy[M % n];
	return abs(xx - ssx) + abs(yy - ssy) <= M;
}
int main(){
	ios::sync_with_stdio(false);
	for(int i = 0; i < 2; i += 1) cin >> x[i] >> y[i];
	cin >> n >> (s + 1);
	for(int i = 1; i <= n; i += 1){
		sx[i] = sx[i - 1];
		sy[i] = sy[i - 1];
		if(s[i] == 'U') sy[i] += 1;
		if(s[i] == 'D') sy[i] -= 1;
		if(s[i] == 'L') sx[i] -= 1;
		if(s[i] == 'R') sx[i] += 1;
	}
	LL L = 0, R = 1E16;
	while(L < R){
		LL M = (L + R) >> 1;
		if(pd(M)) R = M;
		else L = M + 1;
	}
	if(L == (LL)1E16) cout << "-1";
	else cout << L;
}