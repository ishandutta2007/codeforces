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
	string s;
	cin >> s;
	int a[3];
	a[0] = a[1] = a[2] = 0;
	for (itn i = 0; i < n; i++){
		if (s[i] == 'B')
			a[0]++;
		else if (s[i] == 'G')
			a[1]++;
		else
			a[2]++;
	}

	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (a[i])
			cnt++;

	if (cnt == 1){
		for (int i = 0; i < 3; i++){
			if (a[i]){
				cout << "BGR"[i];
			}
		}
		cout << "\n";
	} else {
		if (cnt == 3){
			cout << "BGR\n";
		} else {
			bool ok[3];
			for (int i = 0; i < 3; i++)
				ok[i] = (a[i] == 0);
			int x = -1, y = -1;
			for (int i = 0; i < 3; i++){
				if (a[i]){
					if (x == -1)
						x = i;
					else
						y = i;
				}
			}
			if (a[x] >= 2)
				ok[y] = 1;
			if (a[y] >= 2)
				ok[x] = 1;

			for (int i = 0; i < 3; i++)
				if (ok[i])
					cout << "BGR"[i];
			cout << "\n";
		}
	}

	return 0;
}