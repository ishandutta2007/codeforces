#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

const int N = 32768;
int dis[32770];

void Main(){
	memset(dis, -1, sizeof(dis));
	queue<pi2> q; q.push({0, 0}); dis[0] = 0;
	while (!q.empty()){
		int now = q.front().fr, dst = q.front().sc;
		q.pop();
		{ int nxt = (now-1 + N) % N;
			if (dis[nxt] == -1){ q.push({nxt, dst+1}); dis[nxt] = dst+1; }
		}
		if (~now & 1){
			for (int nxt : {now>>1, (now>>1) + N/2}){
				if (dis[nxt] == -1){ q.push({nxt, dst+1}); dis[nxt] = dst+1; }
			}
		}
	}
	int n; cin >> n;
	while (n--){ int x; cin >> x; cout << dis[x] << ' '; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}