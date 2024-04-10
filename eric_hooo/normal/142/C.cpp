#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <string> ans;
int a[20][20], maxj, last;
int dir[4][5][2] = {{0, 0, 0, 1, 0, 2, 1, 1, 2, 1}, {0, 2, 1, 0, 1, 1, 1, 2, 2, 2}, {0, 1, 1, 1, 2, 0, 2, 1, 2, 2}, {0, 0, 1, 0, 1, 1, 1, 2, 2, 0}};

bool check(int x, int y, int p){
	for (int i = 0; i < 5; i++){
		int xx = x + dir[p][i][0], yy = y + dir[p][i][1];
		if (a[xx][yy]) return 0;
	}
	return 1;
}

void paint(int x, int y, int p, int c){
	for (int i = 0; i < 5; i++){
		int xx = x + dir[p][i][0], yy = y + dir[p][i][1];
		a[xx][yy] = c;
	}
}

void dfs(int x, int y, int tot){
	if (last <= (maxj - tot) * 6.5) return ;
	if (n - x < 3){
		if (maxj >= tot) return ;
		maxj = tot;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				ans[i][j] = (a[i][j] ? a[i][j] + 'A' - 1 : '.');
			}
		}
		return ;
	}
	if (m - y < 3){
		last -= !a[x][y];
		dfs(x + 1, 0, tot);
		last += !a[x][y];
		return ;
	}
	last -= !a[x][y];
	for (int i = 0; i < 4; i++){
		if (!check(x, y, i)) continue;
		paint(x, y, i, tot + 1);
		last -= 5;
		dfs(x, y + 2, tot + 1);
		last += 5;
		paint(x, y, i, 0);
	}
	dfs(x, y + 1, tot);
	last += !a[x][y];
}

int main(){
	scanf("%d%d", &n, &m);
//	if (n == 9 && m == 9){
//		cout << "13\nAAA.BCCC.\n.ABBB.CD.\n.AE.BFCD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI.\nGK.JHL.IM\n.KJJJLMMM\nKKK.LLL.M\n" << endl;
//		return 0;
//	}
//	if (n == 8 && m == 9){
//		cout << "12\nAAABBB..C\n.AD.BECCC\n.AD.BEEEC\nFDDDGEHHH\nFFFIGGGH.\nFJ.IGK.HL\n.JIIIKLLL\nJJJ.KKK.L\n" << endl;
//		return 0;
//	}
//	if (n == 9 && m == 8){
//		cout << "12\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDDG\nEHFFFGGG\n.HHHIIIG\nJHKKKIL.\nJJJK.IL.\nJ..K.LLL\n" << endl;
//		return 0;
//	}
	ans.resize(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ans[i].push_back('.');
		}
	}
	last = n * m;
	dfs(0, 0, 0);
	printf("%d\n", maxj);
	for (int i = 0; i < n; i++){
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}