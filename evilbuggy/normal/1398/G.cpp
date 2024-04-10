#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 25;
const int M = 5e5 + 55;
bool pos[N];
int n, x, y, a[N], mx[M];

void pre(){
	bitset<N> cur, tot;
	cur.set(0, 1);
	for(int i = 1; i <= n; i++){
		cur.set(0, 1);
		cur <<= (a[i] - a[i - 1]);
		tot |= cur;
	}
	for(int i = 0; i < N; i++){
		pos[i] = tot[i];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	cin>>n>>x>>y;
	for(int i = 0; i <= n; i++){
		cin>>a[i];
	}
	pre();
	memset(mx, -1, sizeof(mx));
	for(int len = y + 1; len < M; len++){
		if(len - y < N && pos[len - y]){
			for(int i = len; i < M; i += len){
				mx[i] = len<<1;
			}
		}
	}
	int q; cin>>q;
	while(q--){
		int l; cin>>l;
		cout<<mx[(l>>1)]<<" ";
	}



	return 0;
}