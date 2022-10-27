#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void transfer(vector<int> &a, vector<int> &b, vector<int> &res){
	while(a.size() >= 8){
		for(int i = 0; i < 4; i++){
			b.push_back(a.back());
			a.pop_back();
		}
	}
	for(int x : a){
		res.push_back(x);
	}
}

void print(vector<int> &x){
	for(int y : x){
		cout << y << ' ';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, d;
	cin >> n >> d;
	vector<int> f[10];
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		f[x%10].push_back(x);
	}
	for(int i = 0; i < 10; i++){
		sort(f[i].begin(), f[i].end());
	}
	if(d == 0){
		if(f[0].size() > 0 || (f[2].size() + f[4].size() + f[6].size() + f[8].size() > 0 && f[5].size() > 0)){
			cout << n << '\n';
			for(int i = 0; i < 10; i++){
				print(f[i]);
			}
			cout << '\n';
		}else{
			cout << -1 << '\n';
		}
		exit(0);
	}
	vector<int> res;
	transfer(f[2], f[6], res);
	transfer(f[3], f[1], res);
	transfer(f[4], f[6], res);
	transfer(f[7], f[1], res);
	transfer(f[8], f[6], res);
	transfer(f[9], f[1], res);
	int m = res.size();
	vector<vector<ld> > best(m + 1, vector<ld>(10, -1.0));
	vector<vector<vector<int> > > ans(m + 1, vector<vector<int> >(10));
	best[0][1] = 1;
	for(int i = 0; i < m; i++){
		best[i + 1] = best[i];
		ans[i + 1] = ans[i];
		for(int j = 0; j < 10; j++){
			if(best[i][j] < 0)continue;
			if(best[i + 1][(j*res[i])%10] < best[i][j]*res[i]){
				best[i + 1][(j*res[i])%10] = best[i][j]*res[i];
				ans[i + 1][(j*res[i])%10] = ans[i][j];
				ans[i + 1][(j*res[i])%10].push_back(res[i]);
			}
		}
	}
	if(d == 5){
		if(f[5].size() > 0){
			int tot = f[1].size() + f[3].size() + f[5].size() + f[7].size() + f[9].size();
			cout << tot << '\n';
			print(f[1]);
			print(f[3]);
			print(f[5]);
			print(f[7]);
			print(f[9]);
			cout << '\n';
		}else{
			cout << -1 << '\n';
		}
	}else if(d&1){
		if(d == 1){
			if(f[1].empty() && ans[m][1].empty()){
				cout << -1 << '\n';
			}else{
				int tot = f[1].size() + ans[m][1].size();
				cout << tot << '\n';
				print(f[1]);
				print(ans[m][1]);
				cout << '\n';
			}
		}else{
			if(ans[m][d].empty()){
				cout << -1 << '\n';
			}else{
				int tot = f[1].size() + ans[m][d].size();
				cout << tot << '\n';
				print(f[1]);
				print(ans[m][d]);
				cout << '\n';
			}
		}
	}else{
		if(d == 6){
			if(f[6].empty() && ans[m][6].empty()){
				cout << -1 << '\n';
			}else{
				int tot = f[1].size() + f[6].size() + ans[m][6].size();
				cout << tot << '\n';
				print(f[1]);
				print(f[6]);
				print(ans[m][6]);
				cout << '\n';
			}
		}else{
			if(ans[m][d].empty()){
				cout << -1 << '\n';
			}else{
				int tot = f[1].size() + f[6].size() + ans[m][d].size();
				cout << tot << '\n';
				print(f[1]);
				print(f[6]);
				print(ans[m][d]);
				cout << '\n';
			}
		}
	}


	return 0;
}