#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[50010];
int a[50010], b[50010];
int n;
priority_queue <pii> q;

int main(){
	scanf("%s", s);
	n = strlen(s);
	long long ans = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '?') scanf("%d%d", &a[i], &b[i]), ans += b[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '(') cnt++;
		else cnt--;
		if (s[i] == '?') s[i] = ')', q.push(mp(b[i] - a[i], i));
		if (cnt == -1){
			if (q.empty()){
				printf("-1\n");
				return 0;
			}
			pii t = q.top(); q.pop();
			ans -= t.fi, s[t.se] = '(', cnt += 2;
		}
	}
	if (cnt){
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n", ans);
	printf("%s\n", s);
	return 0;
}