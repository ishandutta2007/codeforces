#include <bits/stdc++.h>
using namespace std;

char a[510][510];
string pos[3] = {"X.X", ".X.", "X.X"};

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n - 3; i++){
		for (int j = 0; j <= n - 3; j++){
			for (int k = 0; k < 3; k++){
				for (int l = 0; l < 3; l++){
					if (a[i + k][j + l] != pos[k][l] && pos[k][l] == 'X') goto END;
				}
			}
			ans++;
			END:;
		}
	}
	printf("%d\n", ans);
	return 0;
}