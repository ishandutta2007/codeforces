#include<bits/stdc++.h>
#define maxn 2400
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
char s[maxn][maxn];
int d[maxn][maxn];
queue<int> q;
vector<int> v[maxn << 1];
bool vis[maxn][maxn];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i += 1) scanf("%s", s[i]);
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < n; j += 1) d[i][j] = maxn * maxn;
	d[0][0] = s[0][0] != 'a';
	q.push(0);
	while(q.empty() == false){
		int x = q.front() / n, y = q.front() % n;
		q.pop();
		if(x + 1 < n && d[x + 1][y] > d[x][y] + (s[x + 1][y] != 'a')){
			d[x + 1][y] = d[x][y] + (s[x + 1][y] != 'a');
			q.push((x + 1) * n + y);
		}
		if(y + 1 < n && d[x][y + 1] > d[x][y] + (s[x][y + 1] != 'a')){
			d[x][y + 1] = d[x][y] + (s[x][y + 1] != 'a');
			q.push(x * n + y + 1);
		}
	}
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < n; j += 1)
			if(d[i][j] <= k) s[i][j] = 'a';
	
	
	/*for(int i = 0; i < n; i += 1){
		for(int j = 0; j < n; j += 1) printf("%d ", d[i][j]);
		printf("\n");
	}
	for(int i = 0; i < n; i += 1) printf("%s\n", s[i]);*/
	char m = s[0][0];
	v[0].push_back(0);
	vis[0][0] = true;
	for(int i = 0; i < 2 * n - 1; i += 1){
		printf("%c", m);
		char pm = 'a' + 26;
		for(int p : v[i]){
			int x = p / n, y = p % n;
			if(s[x][y] == m){
				if(x + 1 < n && vis[x + 1][y] == false){
					pm = min(s[x + 1][y], pm);
					v[i + 1].push_back((x + 1) * n + y);
					vis[x + 1][y] = true;
				}
				if(y + 1 < n && vis[x][y + 1] == false){
					pm = min(s[x][y + 1], pm);
					v[i + 1].push_back(x * n + y + 1);
					vis[x][y + 1] = true;
				}
			}
		}
		m = pm; 
	}
}