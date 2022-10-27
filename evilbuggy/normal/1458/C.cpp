#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N], b[N][N], p[N];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	string s;
	cin >> s;
	int transpose = 0;
	int totr = 0, totd = 0, tota = 0;
	auto apply = [&](int op, int cnt){
		if(op == 0){
			totr += cnt;
		}else if(op == 1){
			totd += cnt;
		}else if(op == 2){
			tota += cnt;
		}else if(op == 3){
			swap(totr, totd);
			transpose ^= 1;
		}
	};
	int prev = -1, r = 0, d = 0;
	for(int i = 0; i < m; i++){
		if(s[i] == 'R'){
			r++;
		}else if(s[i] == 'L'){
			r--;
		}else if(s[i] == 'D'){
			d++;
		}else if(s[i] == 'U'){
			d--;
		}else if(prev == -1){
			apply(0, r);
			apply(1, d);
			r = d = 0;
			prev = i;
		}else{
			if(s[prev] == 'I' && s[i] == 'I'){
				apply(1, d);
				apply(2, r);
				r = d = 0;
				prev = -1;
			}else if(s[prev] == 'C' && s[i] == 'C'){
				apply(0, r);
				apply(2, d);
				r = d = 0;
				prev = -1;
			}else if(s[prev] == 'I' && s[i] == 'C'){
				apply(1, d);
				apply(3, 0);
				s[i] = 'I';
				prev = i;
				d = 0;
			}else{
				apply(0, r);
				apply(3, 0);
				s[i] = 'C';
				prev = i;
				r = 0;
			}
		}
	}
	if(transpose){
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				swap(a[i][j], a[j][i]);
			}
		}
	}
	totr %= n; if(totr < 0)totr += n;
	totd %= n; if(totd < 0)totd += n;
	tota %= n; if(tota < 0)tota += n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i][j] = a[(i - totd + n)%n][(j - totr + n)%n];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = (b[i][j] + tota)%n;
		}
	}
	if(prev != -1){
		if(s[prev] == 'I'){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					p[a[i][j]] = j;
				}
				for(int j = 0; j < n; j++){
					a[i][j] = p[j];
				}
			}
		}else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					p[a[j][i]] = j;
				}
				for(int j = 0; j < n; j++){
					a[j][i] = p[j];
				}
			}
		}
	}
	r %= n; if(r < 0)r += n;
	d %= n; if(d < 0)d += n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[(i - d + n)%n][(j - r + n)%n] + 1 << " ";
		}
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}