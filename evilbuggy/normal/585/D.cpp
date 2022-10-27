#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int a[N], b[N], c[N];

void dfs(int i, int ca, int cb, int cc, int a[], int b[], int c[], int n, vector<array<int, 3> > &vec){
	if(i == n){
		vec.push_back({ca, cb, cc});
		return;
	}
	dfs(i + 1, ca + a[i], cb + b[i], cc, a, b, c, n, vec);
	dfs(i + 1, ca + a[i], cb, cc + c[i], a, b, c, n, vec);
	dfs(i + 1, ca, cb + b[i], cc + c[i], a, b, c, n, vec);
}

bool dfs1(int i, int ca, int cb, int cc, int a[], int b[], int c[], int n, vector<string> &moves){
	if(i == n){
		if(ca == 0 && cb == 0 && cc == 0){
			for(auto x : moves){
				cout << x << '\n';
			}
			return true;
		}
		return false;
	}
	{
		moves.push_back("LM");
		if(dfs1(i + 1, ca - a[i], cb - b[i], cc, a, b, c, n, moves))return true;
		moves.pop_back();
	}
	{
		moves.push_back("MW");
		if(dfs1(i + 1, ca, cb - b[i], cc - c[i], a, b, c, n, moves))return true;
		moves.pop_back();
	}
	{
		moves.push_back("LW");
		if(dfs1(i + 1, ca - a[i], cb, cc - c[i], a, b, c, n, moves))return true;
		moves.pop_back();
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int n1 = n/2;
	int n2 = n - n1;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<array<int, 3> > vec1;
	vector<array<int, 3> > vec2;
	dfs(0, 0, 0, 0, a, b, c, n1, vec1);
	dfs(0, 0, 0, 0, a + n1, b + n1, c + n1, n2, vec2);
	for(auto &x : vec1){
		x[0] = x[2] - x[0];
		x[1] = x[2] - x[1];
	}
	int sz = 1;
	sort(vec1.begin(), vec1.end());
	for(int i = 1; i < (int)vec1.size(); i++){
		if(vec1[sz - 1][0] == vec1[i][0] && vec1[sz - 1][1] == vec1[i][1]){
			vec1[sz - 1][2] = vec1[i][2];
		}else{
			vec1[sz] = vec1[i]; ++sz;
		}
	}
	vec1.resize(sz);
	bool found = false;
	long long answer = -1e18;
	int ca1 = 0, cb1 = 0, cc1 = 0;
	int ca2 = 0, cb2 = 0, cc2 = 0;
	for(auto x : vec2){
		array<int, 3> y;
		y[0] = x[0] - x[2];
		y[1] = x[1] - x[2];
		y[2] = -1e9;
		int ind = lower_bound(vec1.begin(), vec1.end(), y) - vec1.begin();
		if(ind < sz && vec1[ind][0] == y[0] && vec1[ind][1] == y[1]){
			if(answer < vec1[ind][2] + x[2]){
				answer = vec1[ind][2] + x[2];
				ca1 = answer - x[0]; ca2 = x[0];
				cb1 = answer - x[1]; cb2 = x[1];
				cc1 = answer - x[2]; cc2 = x[2];
			}
			found = true;
		}
	}
	if(!found){
		cout << "Impossible" << '\n';
		exit(0);
	}
	vector<string> moves;
	dfs1(0, ca1, cb1, cc1, a, b, c, n1, moves); moves.clear();
	dfs1(0, ca2, cb2, cc2, a + n1, b + n1, c + n1, n2, moves);

	return 0;
}