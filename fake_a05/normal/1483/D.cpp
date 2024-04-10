#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int>
#define ii pair<int, int>
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 605, mod = 1e9 + 7, inf = LLONG_MAX / 100ll;

int N, M, Q; 
int d[maxN][maxN], w[maxN][maxN], l[maxN][maxN], mx[maxN][maxN];
bool ok[maxN][maxN];


void prep(){
	loop(i, 1, N){
		loop(j, 1, N){
			d[i][j] = w[i][j] = inf;
			l[i][j] = -inf;
			mx[i][j] = -inf;
		}
		d[i][i] = w[i][i] = 0;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	prep();
	loop(i, 1, M){
		int u, v, c;
		cin >> u >> v >> c;
		w[u][v] = w[v][u] = c;
		d[u][v] = d[v][u] = c;
	}
	cin >> Q;
	loop(i, 1, Q){
		int u, v, c;
		cin >> u >> v >> c;
		l[u][v] = l[v][u] = c;
	}
	loop(k,1, N){
		loop(i, 1, N){
			loop(j, 1, N){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	loop(u, 1, N){
		loop(a, 1, N){
			if(u == a) continue;
			loop(b, 1, N){
				if(b == a) continue;
				mx[u][a] = max(mx[u][a], l[a][b] - d[u][b]);
			}
		}
	}
	loop(u, 1, N){
		loop(a, 1, N){
			loop(v, 1, N){
				if(v == u) continue;
				if(w[u][v] + d[v][a] <= mx[u][a]) ok[u][v] = 1;
			}
		}
	}
	int ans = 0;
	loop(u, 1, N){
		loop(v, 1, N){
			if(u == v) continue;
			ans += ok[u][v];
		}
	}
	cout << ans / 2;
}