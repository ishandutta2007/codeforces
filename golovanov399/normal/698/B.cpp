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
	for (int i = 0; i < n; i++)
		a[i] = nxt() - 1;

	vector<char> used(n);
	vector<int> tofix;
	for (int i = 0; i < n; i++){
		if (used[i])
			continue;

		int v = i;
		vector<int> way;
		while (!used[v]){
			used[v] = 1;
			way.push_back(v);
			v = a[v];
		}
		if (used[v] == 1){
			tofix.push_back(v);
		}
		for (auto x : way)
			used[x]++;
	}

	int index = -1;
	for (int i = 0; i < tofix.size(); i++){
		if (a[tofix[i]] == tofix[i])
			index = i;
	}

	int ans = tofix.size();
	if (index > -1)
		ans--;
	printf("%d\n", ans);
	if (index == -1){
		index = 0;
	}
	for (int i = 0; i < (int)tofix.size(); i++){
		a[tofix[i]] = tofix[index];
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i] + 1);
	printf("\n");

	return 0;
}