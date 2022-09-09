#include<bits/stdc++.h>
#define maxn 1200
#define maxm 1200
using namespace std;
char s[maxn], t[maxm];
bool occ[maxn];
int ss[maxn];
int main(){
	int n, m, q;
	scanf("%d %d %d %s %s", &n, &m, &q, s + 1, t + 1);
	for(int i = 1; i <= n; i += 1){
		occ[i] = true;
		if(i + m - 1 > n) occ[i] = false;
		else for(int j = 1; j <= m; j += 1) if(s[i + j - 1] != t[j]) occ[i] = false;
		ss[i] = ss[i - 1];
		if(occ[i]) ss[i] += 1;
		//printf("ss[%d] = %d\n", i, ss[i]);
	}
	for(int i = 0; i < q; i += 1){
		int l, r;
		scanf("%d %d", &l, &r);
		if(r - l + 1 < m) printf("0\n");
		else printf("%d\n", ss[r - m + 1] - ss[l - 1]);
	}
}