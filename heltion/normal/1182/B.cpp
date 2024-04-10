//Author: Heltion
//Date: 2019-06-11
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600;
char s[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int h, w;
	cin >> h >> w;
	for(int i = 1; i <= h; i += 1) cin >> (s[i] + 1);
	int ci = 0, cj = 0;
	for(int i = 1; i <= h; i += 1)
		for(int j = 1; j <= w; j += 1)
			if(s[i][j] == '*')
				if(s[i][j + 1] == '*')
					if(s[i + 1][j] == '*')
						if(s[i - 1][j] == '*')
							if(s[i][j - 1] == '*')
								ci = i, cj = j;
	//cout << ci << " " << cj << endl;
	if(not ci){
		cout << "NO";
		return 0;
	}
	for(int i = ci - 1; i; i -= 1)
		if(s[i][cj] != '*') break;
		else s[i][cj] = '#';
	for(int i = ci + 1; i <= h; i += 1)
		if(s[i][cj] != '*') break;
		else s[i][cj] = '#';
	for(int j = cj - 1; j; j -= 1)
		if(s[ci][j] != '*') break;
		else s[ci][j] = '#';
	for(int j = cj + 1; j <= w; j += 1)
		if(s[ci][j] != '*') break;
		else s[ci][j] = '#';
	s[ci][cj] = '#';
	for(int i = 1; i <= h; i += 1)
		for(int j = 1; j <= w; j += 1)
			if(s[i][j] == '*'){
				cout << "NO";
				return 0;
			}
	cout << "YES";
	return 0;
}