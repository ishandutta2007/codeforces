#include <bits/stdc++.h>
using namespace std;

char ans[105][105];

inline void print(int n, int m){
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

char get(int x1, int y1, int x2, int y2){
	set<char> st;
	if(x1 > 0)st.insert(ans[x1 - 1][y1]);
	if(x2 > 0)st.insert(ans[x2 - 1][y2]);
	if(y1 > 0)st.insert(ans[x1][y1 - 1]);
	if(y2 > 0)st.insert(ans[x2][y2 - 1]);
	for(char ch = 'a'; ch <= 'z'; ch++){
		if(!st.count(ch))return ch;
	}
	return 'z';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		char ch;
		int n, m, k;
		cin >> n >> m >> k;
		if(n%2 == 0 && m%2 == 0){
			if(k%2 != 0){
				cout << "NO" << '\n';
			}else{
				for(int i = 0; i < n; i += 2){
					for(int j = 0; j < m; j += 2){
						if(k == 0){
							ch = get(i, j, i + 1, j);
							ans[i][j] = ans[i + 1][j] = ch;
							ch = get(i, j + 1, i + 1, j + 1);
							ans[i][j + 1] = ans[i + 1][j + 1] = ch;
						}else{
							ch = get(i, j, i, j + 1);
							ans[i][j] = ans[i][j + 1] = ch;
							ch = get(i + 1, j, i + 1, j + 1);
							ans[i + 1][j] = ans[i + 1][j + 1] = ch;
							k -= 2;
						}
					}
				}
				print(n, m);
			}
		}else if(n%2 == 0 && m%2 == 1){
			if(k%2 != 0){
				cout << "NO" << '\n';
			}else if(k > n*(m - 1)/2){
				cout << "NO" << '\n';
			}else{
				for(int i = 0; i < n; i += 2){
					for(int j = 0; j < m; j += 2){
						if(k == 0 || j == m - 1){
							ch = get(i, j, i + 1, j);
							ans[i][j] = ans[i + 1][j] = ch;
							ch = get(i, j + 1, i + 1, j + 1);
							ans[i][j + 1] = ans[i + 1][j + 1] = ch;
						}else{
							ch = get(i, j, i, j + 1);
							ans[i][j] = ans[i][j + 1] = ch;
							ch = get(i + 1, j, i + 1, j + 1);
							ans[i + 1][j] = ans[i + 1][j + 1] = ch;
							k -= 2;
						}
					}
				}
				print(n, m);
			}
		}else if(n%2 == 1 && m%2 == 0){
			if(k < m/2){
				cout << "NO" << '\n';
			}else{
				k -= m/2;
				if(k%2 != 0){
					cout << "NO" << '\n';
				}else{
					for(int j = 0; j < m; j += 2){
						if(j%4 == 0){
							ans[0][j] = ans[0][j + 1] = 'a';
						}else{
							ans[0][j] = ans[0][j + 1] = 'b';
						}
					}
					for(int i = 1; i < n; i += 2){
						for(int j = 0; j < m; j += 2){
							if(k == 0){
								ch = get(i, j, i + 1, j);
								ans[i][j] = ans[i + 1][j] = ch;
								ch = get(i, j + 1, i + 1, j + 1);
								ans[i][j + 1] = ans[i + 1][j + 1] = ch;
							}else{
								ch = get(i, j, i, j + 1);
								ans[i][j] = ans[i][j + 1] = ch;
								ch = get(i + 1, j, i + 1, j + 1);
								ans[i + 1][j] = ans[i + 1][j + 1] = ch;
								k -= 2;
							}
						}
					}
					print(n, m);
				}
			}
		}
	}

	return 0;
}