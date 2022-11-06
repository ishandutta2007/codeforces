#include<bits/stdc++.h>
#define maxn 200
using namespace std;
typedef long long LL;
char s[maxn][maxn];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int U = 0, P = 0, L = 0, R = 0;
	for(int i = 1; i <= n; i += 1){
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j += 1){
			if(s[i][j] == 'B'){
				if(U == 0) U = i;
				if(L == 0) L = j;
				P = i;
				R = j;
			}
		}
	}
	printf("%d %d\n", (U + P) / 2, (L + R) / 2);
}