#include<bits/stdc++.h>
#define maxn 120
using namespace std;
int a[maxn];
int main(){
	int n, m, u = 0, s = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i += 1){
		scanf("%d", a + i);
		u = max(a[i], u);
	}
	for(int i = 0; i < n; i += 1) s += u - a[i];
	printf("%d %d", s >= m ? u : (m - s + n - 1) / n + u, u + m);
	
}