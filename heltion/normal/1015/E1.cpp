#include<bits/stdc++.h>
#define maxn 1200
#define maxm 1200
using namespace std;
char s[maxn][maxm];
int Left[maxn][maxm], Right[maxn][maxm], Up[maxn][maxm], Down[maxn][maxm];
int ans[maxn][maxm];
char draw[maxn][maxm];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i += 1) scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1)
			if(s[i][j] == '.') Left[i][j] = 0;
			else Left[i][j] = Left[i][j - 1] + 1;
			
	for(int i = 1; i <= n; i += 1)
		for(int j = m; j >= 1; j -= 1)
			if(s[i][j] == '.') Right[i][j] = 0;
			else Right[i][j] = Right[i][j + 1] + 1;
			
	for(int j = 1; j <= m; j += 1)
		for(int i = 1; i <= n; i += 1)
			if(s[i][j] == '.') Up[i][j] = 0;
			else Up[i][j] = Up[i - 1][j] + 1;
			
	for(int j = 1; j <= m; j += 1)
		for(int i = n; i >= 1; i -= 1)
			if(s[i][j] == '.') Down[i][j] = 0;
			else Down[i][j] = Down[i + 1][j] + 1;
	
	vector<pair<int, int> > ansv;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1){
			//printf("%d %d %d %d %d %d\n", i, j, Left[i][j], Right[i][j], Up[i][j], Down[i][j]);
			draw[i][j] = '.';
			ans[i][j] = min(min(Left[i][j], Right[i][j]), min(Up[i][j], Down[i][j]));
			if(ans[i][j]) ans[i][j] -= 1;
			if(ans[i][j]) ansv.push_back({i, j});
			//printf("%d %d %d\n", i, j, ans[i][j]);
		}
	
	for(int i = 1; i <= n; i += 1){
		int k = 0;
		for(int j = 1; j <= m; j += 1){
			if(ans[i][j])k = max(ans[i][j] + 1, k);
			if(k){
				draw[i][j] = '*';
				k -= 1;
			} 
		}
	}
	
	for(int i = 1; i <= n; i += 1){
		int k = 0;
		for(int j = m; j >= 1; j -= 1){
			if(ans[i][j])k = max(ans[i][j] + 1, k);
			if(k){
				draw[i][j] = '*';
				k -= 1;
			} 
		}
	}
			
	for(int j = 1; j <= m; j += 1){
		int k = 0;
		for(int i = 1; i <= n; i += 1){
			if(ans[i][j])k = max(ans[i][j] + 1, k);
			if(k){
				draw[i][j] = '*';
				k -= 1;
			} 
		}
	}
			
	for(int j = 1; j <= m; j += 1){
		int k = 0;
		for(int i = n; i >= 1; i -= 1){
			if(ans[i][j])k = max(ans[i][j] + 1, k);
			if(k){
				draw[i][j] = '*';
				k -= 1;
			} 
		}
	}
	bool flag = true;
	for(int i = 1; i <= n; i += 1){
		//printf("%s\n", draw[i] + 1);
		if(strcmp(draw[i] + 1, s[i] + 1))
			flag = false;
	}
		
	if(flag == false) printf("-1");
	else{
		printf("%d\n", (int)ansv.size());
		for(auto p: ansv){
			printf("%d %d %d\n", p.first, p.second, ans[p.first][p.second]);
		}
	}
}