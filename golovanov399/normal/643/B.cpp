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
	int k = nxt();
	vector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = nxt();

	vector<int> others;
	for (int i = 1; i <= n; i++){
		bool ok = true;
		for (int j = 0; j < 4; j++){
			if (v[j] == i)
				ok = false;
		}
		if (ok)
			others.push_back(i);
	}

	if (n == 4){
		puts("-1");
		return 0;
	} else {
		if (k >= n + 1){
			cout << v[0] << " " << v[2] << " ";
			for (auto x : others)
				cout << x << " ";
			cout << v[3] << " " << v[1] << "\n";
			cout << v[2] << " " << v[0] << " ";
			for (auto x : others)
				cout << x << " ";
			cout << v[1] << " " << v[3] << "\n";
		} else
			puts("-1");
	}

	return 0;
}