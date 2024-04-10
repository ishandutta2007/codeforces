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
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector<set<int> > a(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (s[i][j] == '1')
				a[j].insert(i);
		}
	}
	vector<int> ar(n);
	for (int i = 0; i < n; i++)
		ar[i] = nxt();
	set<int> ppl;
	for (int i = 0; i < n; i++)
		ppl.insert(i);
	while (true){
		set<int> tokill;
		for (auto x : ppl){
			if (ar[x] >= a[x].size()){
				tokill.insert(x);
			}
		}
		if (tokill.empty()){
			printf("%d\n", (int)ppl.size());
			for (auto x : ppl){
				printf("%d ", x + 1);
			}
			puts("");
			return 0;
		} else {
			for (auto x : ppl){
				for (auto y : tokill){
					if (a[x].find(y) != a[x].end())
						a[x].erase(y);
				}
			}
			for (auto x : tokill)
				ppl.erase(x);
		}
	}

	return 0;
}