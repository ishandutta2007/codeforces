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

int main(){

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt() - 1;
	}
	vector<vector<int>> p;
	vector<char> used(n);
	for (int i = 0; i < n; i++){
		if (!used[i]){
			int v = i;
			p.push_back(vector<int>(0));
			while (!used[v]){
				used[v] = 1;
				p.back().push_back(v);
				v = a[v];
			}
		}
	}
	sort(all(p), [](const vector<int>& x, const vector<int>& y){
		return x.size() < y.size();
	});
	if (p[0].size() == 1){
		puts("YES");
		for (int i = 0; i < n; i++){
			if (i == p[0][0])
				continue;
			printf("%d %d\n", p[0][0] + 1, i + 1);
		}
	} else
	if (p[0].size() == 2){
		for (int i = 1; i < p.size(); i++){
			if (p[i].size() % 2){
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		for (int i = 1; i < p.size(); i++){
			for (int j = 0; j < p[i].size(); j++){
				printf("%d %d\n", p[i][j] + 1, p[0][j % 2] + 1);
			}
		}
		printf("%d %d\n", p[0][0] + 1, p[0][1] + 1);
	} else {
		puts("NO");
	}

	return 0;
}