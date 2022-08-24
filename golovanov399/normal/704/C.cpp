#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

pair<int, int> solve_path(const vector<pair<char, char>>& a){
	pair<long long, long long> cur[2] = {{1, 0}, {1, 0}};
	pair<long long, long long> tmp[2];
	for (const auto& p: a){
		if (p.first == 0 && p.second == 0){
			tmp[0] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
			tmp[1] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
		} else
		if (p.first == 0 && p.second == 1){
			tmp[0] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
			tmp[1] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
		} else
		if (p.first == 1 && p.second == 0){
			tmp[0] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
			tmp[1] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
		} else
		if (p.first == 1 && p.second == 1){
			tmp[0] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
			tmp[1] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
		}
		for (int i = 0; i < 2; i++){
			tmp[i].first %= mod;
			tmp[i].second %= mod;
			cur[i] = tmp[i];
		}
	}
	return {(cur[0].first + cur[1].first) % mod, (cur[0].second + cur[1].second) % mod};
}

pair<int, int> solve_pathl(const vector<pair<char, char>>& a, bool rev){
	pair<long long, long long> cur[2] = {{1, 0}, {0, 1}};
	if (rev)
		swap(cur[0], cur[1]);
	pair<long long, long long> tmp[2];
	for (const auto& p: a){
		if (p.first == 0 && p.second == 0){
			tmp[0] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
			tmp[1] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
		} else
		if (p.first == 0 && p.second == 1){
			tmp[0] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
			tmp[1] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
		} else
		if (p.first == 1 && p.second == 0){
			tmp[0] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
			tmp[1] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
		} else
		if (p.first == 1 && p.second == 1){
			tmp[0] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
			tmp[1] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
		}
		for (int i = 0; i < 2; i++){
			tmp[i].first %= mod;
			tmp[i].second %= mod;
			cur[i] = tmp[i];
		}
	}
	return {(cur[0].first + cur[1].first) % mod, (cur[0].second + cur[1].second) % mod};
}

pair<int, int> solve_pathr(const vector<pair<char, char>>& a, bool rev){
	pair<long long, long long> cur[2] = {{1, 0}, {1, 0}};
	pair<long long, long long> tmp[2];
	for (const auto& p: a){
		if (p.first == 0 && p.second == 0){
			tmp[0] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
			tmp[1] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
		} else
		if (p.first == 0 && p.second == 1){
			tmp[0] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
			tmp[1] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
		} else
		if (p.first == 1 && p.second == 0){
			tmp[0] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
			tmp[1] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
		} else
		if (p.first == 1 && p.second == 1){
			tmp[0] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
			tmp[1] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
		}
		for (int i = 0; i < 2; i++){
			tmp[i].first %= mod;
			tmp[i].second %= mod;
			cur[i] = tmp[i];
		}
	}
	if (rev)
		return {(cur[0].second + cur[1].first) % mod, (cur[0].first + cur[1].second) % mod};
	else
		return {(cur[0].first + cur[1].second) % mod, (cur[0].second + cur[1].first) % mod};
}

pair<int, int> solve_pathlr(const vector<pair<char, char>>& a, bool rev1, bool rev2){
	pair<long long, long long> cur[2] = {{1, 0}, {0, 1}};
	if (rev1)
		swap(cur[0], cur[1]);
	pair<long long, long long> tmp[2];
	for (const auto& p: a){
		if (p.first == 0 && p.second == 0){
			tmp[0] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
			tmp[1] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
		} else
		if (p.first == 0 && p.second == 1){
			tmp[0] = {cur[0].second + cur[1].second, cur[0].first + cur[1].first};
			tmp[1] = {cur[0].first + cur[1].second, cur[0].second + cur[1].first};
		} else
		if (p.first == 1 && p.second == 0){
			tmp[0] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
			tmp[1] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
		} else
		if (p.first == 1 && p.second == 1){
			tmp[0] = {cur[1].second + cur[0].second, cur[1].first + cur[0].first};
			tmp[1] = {cur[1].first + cur[0].second, cur[1].second + cur[0].first};
		}
		for (int i = 0; i < 2; i++){
			tmp[i].first %= mod;
			tmp[i].second %= mod;
			cur[i] = tmp[i];
		}
	}
	if (rev2)
		return {(cur[0].second + cur[1].first) % mod, (cur[0].first + cur[1].second) % mod};
	else
		return {(cur[0].first + cur[1].second) % mod, (cur[0].second + cur[1].first) % mod};
}

pair<int, int> solve_cycle(const vector<pair<char, char>>& a){
	pair<long long, long long> cur[2][2] = {{{1, 0}, {0, 0}}, {{0, 0}, {1, 0}}};
	pair<long long, long long> tmp[2];
	for (int ij = 0; ij < (int)a.size() - 1; ij++){
		auto p = a[ij];
		for (int j = 0; j < 2; j++){
			if (p.first == 0 && p.second == 0){
				tmp[0] = {cur[j][0].first + cur[j][1].second, cur[j][0].second + cur[j][1].first};
				tmp[1] = {cur[j][0].second + cur[j][1].second, cur[j][0].first + cur[j][1].first};
			} else
			if (p.first == 0 && p.second == 1){
				tmp[0] = {cur[j][0].second + cur[j][1].second, cur[j][0].first + cur[j][1].first};
				tmp[1] = {cur[j][0].first + cur[j][1].second, cur[j][0].second + cur[j][1].first};
			} else
			if (p.first == 1 && p.second == 0){
				tmp[0] = {cur[j][1].first + cur[j][0].second, cur[j][1].second + cur[j][0].first};
				tmp[1] = {cur[j][1].second + cur[j][0].second, cur[j][1].first + cur[j][0].first};
			} else
			if (p.first == 1 && p.second == 1){
				tmp[0] = {cur[j][1].second + cur[j][0].second, cur[j][1].first + cur[j][0].first};
				tmp[1] = {cur[j][1].first + cur[j][0].second, cur[j][1].second + cur[j][0].first};
			}
			for (int i = 0; i < 2; i++){
				tmp[i].first %= mod;
				tmp[i].second %= mod;
				cur[j][i] = tmp[i];
			}
		}
	}

	return {(cur[a.back().second][a.back().first].first + cur[a.back().second ^ 1][a.back().first].second + cur[a.back().second][a.back().first ^ 1].second + cur[a.back().second ^ 1][a.back().first ^ 1].second) % mod,
			(cur[a.back().second][a.back().first].second + cur[a.back().second ^ 1][a.back().first].first + cur[a.back().second][a.back().first ^ 1].first + cur[a.back().second ^ 1][a.back().first ^ 1].first) % mod};
}

int main(){

	int n = nxt(), m = nxt();
	int intended = 1;
	vector<char> zalupa(m, 2);
	vector<vector<int>> eds(m);
	vector<pair<int, int>> ed;
	for (int i = 0; i < n; i++){
		int k = nxt();
		int x, y;
		if (k == 1)
			x = y = nxt();
		else
			x = nxt(), y = nxt();

		if (x == -y){
			intended ^= 1;
			// zalupa[abs(x) - 1] = 3;
		} else if (x == y){
			zalupa[abs(x) - 1] = (x < 0);
		} else {
			int i1 = abs(x) - 1, i2 = abs(y) - 1;
			eds[i1].push_back(ed.size());
			eds[i2].push_back(ed.size());
			ed.push_back({x, y});
		}
	}

	pair<long long, long long> ans = {1, 0};
	vector<char> used(m);
	for (int i = 0; i < m; i++){
		if (!used[i] && eds[i].size() == 1){
			int pr = -1;
			int v = i;
			used[v] = 1;
			vector<pair<char, char>> edges;
			do {
				int ind = eds[v][0];
				if (abs(ed[ind].first) - 1 != v)
					swap(ed[ind].first, ed[ind].second);
				eds[v].clear();
				// cerr << v + 1 << ": " << ind + 1 << ", " << ed[ind].first << " " << ed[ind].second << "\n";
				edges.push_back({ed[ind].first < 0, ed[ind].second < 0});
				v = abs(ed[ind].second) - 1;
				if (eds[v][0] == ind)
					eds[v].erase(eds[v].begin());
				else
					eds[v].pop_back();
				used[v] = 1;
			} while (!eds[v].empty());
			// cerr << "qwe\n";
			pair<int, int> p;
			// cerr << (int)zalupa[i] << " " << (int)zalupa[v] << " adf\n";
			if (zalupa[i] != 2 && zalupa[v] != 2)
				p = solve_pathlr(edges, zalupa[i], zalupa[v]);
			else if (zalupa[i] != 2)
				p = solve_pathl(edges, zalupa[i]);
			else if (zalupa[v] != 2)
				p = solve_pathr(edges, zalupa[v]);
			else
				p = solve_path(edges);
			ans = {(ans.first * p.first + ans.second * p.second) % mod,
				   (ans.first * p.second + ans.second * p.first) % mod};
		}
	}

	for (int i = 0; i < m; i++){
		if (!used[i] && eds[i].size() == 2){
			int v = i;
			vector<pair<char, char>> edges;
			do {
				used[v] = 1;
				int ind = eds[v][0];
				if (abs(ed[ind].first) - 1 != v)
					swap(ed[ind].first, ed[ind].second);
				eds[v].clear();
				edges.push_back({ed[ind].first < 0, ed[ind].second < 0});
				v = abs(ed[ind].second) - 1;
				if (v != i){
					if (eds[v][0] == ind)
						eds[v].erase(eds[v].begin());
					else
						eds[v].erase(eds[v].begin() + 1);
				}
				// used[v] = 1;
			} while (v != i);
			pair<int, int> p = solve_cycle(edges);
			ans = {(ans.first * p.first + ans.second * p.second) % mod,
				   (ans.first * p.second + ans.second * p.first) % mod};
		}
	}

	for (int i = 0; i < m; i++){
		if (!used[i] && zalupa[i] == 2){
			ans = {ans.first * 2 % mod, ans.second * 2 % mod};
		}
	}

	for (int i = 0; i < m; i++){
		if (!used[i] && zalupa[i] < 2){
			ans = {(ans.first + ans.second) % mod, (ans.first + ans.second) % mod};
		}
	}

	cout << (intended ? ans.second : ans.first) << "\n";

	return 0;
}