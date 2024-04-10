//Powered by Buggy plugin
//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}

constexpr int maxn = 54;
char s[maxn][maxn];
void check(int i, int j, int n){
	if(not ~i or i == n or not ~j or j == n or s[i][j] == '#') no("NO");
	s[i][j] = '#';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> s[i];
	while(true){
		int x = -1, y = -1;
		for(int i = 0; i < n; i += 1)
			for(int j = 0; j < n; j += 1)
				if(not ~x and s[i][j] == '.')
					x = i, y = j;
		if(not ~x) break;
		check(x, y, n);
		check(x + 1, y - 1, n);
		check(x + 1, y, n);
		check(x + 1, y + 1, n);
		check(x + 2, y, n);
	}
	cout << "YES";
	return 0;
}