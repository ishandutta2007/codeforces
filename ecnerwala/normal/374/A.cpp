#include<iostream>
#include<cmath>

using namespace std;

const int INF = 1 << 30;

int N, M, I, J, A, B;

//start, end
int dist(int i, int j, int x, int y) {
	x -= i;
	if(x < 0) x = -x;
	y -= j;
	if(y < 0) y = -y;
	if(x % A != 0) return INF;
	if(y % B != 0) return INF;
	x /= A;
	y /= B;
	if(x % 2 != y % 2) return INF;
if(x == 0 && y == 0) return 0;
	return max(x, y);
}

int go() {
if((I == 1 || I == N) && (J == 1 || J == M)) return 0;
if((I - A > 0 || I + A <= N) && (J - B > 0 || J  + B <= M))
	return min(min(dist(I, J, 1, 1), dist(I, J, 1, M)), min(dist(I, J, N, 1), dist(I, J, N, M)));
return INF;
}

int main() {
	cin >> N >> M >> I >> J >> A >> B;

	int ans = go();
	if(ans == INF) cout << "Poor Inna and pony!" << '\n';
	else cout << ans << '\n';

	return 0;
}