#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read(){LL x; scanf("%lld", &x); return x;}
void read(char *s){scanf("%s", s);}
void no(){printf("-1"); exit(0);}

#define maxn 400000

LL a[maxn], b[maxn];

int main(){
	LL sa = 0, sb = 0;
	int n = read();
	for(int i = 0; i < n; i += 1)
		sa += a[i] = read();
	int m = read();
	for(int i = 0; i < m; i += 1)
		sb += b[i] = read();
	if(sa != sb) no();
	int ans = 0;
	for(int i = 0, j = 0; i < n && j < m;){
		if(a[i] == b[j]){
			ans += 1;
			i += 1;
			j += 1;
		}
		else if(a[i] > b[j]){
			b[j + 1] += b[j];
			j += 1;
		}
		else{
			a[i + 1] += a[i];
			i += 1;
		}
	}
	printf("%d", ans);
}