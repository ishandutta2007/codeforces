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

	vector<int> cnt(n);
	for (int i = 0; i < n; i++){
		pair<int, int> mn;
		vector<int> cn(n);
		for (int j = i; j < n; j++){
			cn[a[j]]++;
			if (cn[a[j]] > mn.first || cn[a[j]] == mn.first && a[j] < mn.second){
				mn = {cn[a[j]], a[j]};
			}
			
			int cl = mn.second;
			cnt[cl]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << cnt[i] << " ";
	cout << "\n";

	return 0;
}