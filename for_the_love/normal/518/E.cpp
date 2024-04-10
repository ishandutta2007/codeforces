#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int flag = 0;
int Get(){
	char s[20];
	scanf("%s", s);
	if (!strcmp(s, "?")) return INF;
	int l, p;
	if (s[0] == '-') l = 1, p = -1; else l = 0, p = 1;
	int ret = 0;
	for (int i = l; i < strlen(s); i++){
		ret = ret * 10 + s[i] - '0';
	}
	return ret * p;
}

int a[111111];
int n, m;

void Get(LL l, LL r, LL cnt, int last){
	if (r - l + 1 < cnt){
		flag = 1;
		return;
	}
	if (r <= 0){
		//LL t = abs(r);
		//return (t + t + cnt - 1) * cnt / 2;
		for (int i = r; i >= r - cnt + 1; i--){
			a[last] = i;
			last -= m;
		}
	}else if (l >= 0){
		//return (l + l + cnt - 1) * cnt / 2;
		for (int i = l + cnt - 1; i >= l; i--){
			a[last] = i;
			last -= m;
		}
	}else{
		LL t = min(abs(l), r);
		if ((cnt - 1) / 2 <= t){
			LL A = (cnt - 1) / 2;
			LL B = cnt - A - 1;
			if (abs(l) <= r){
				for (int i = B; i >= -A; i--){
					a[last] = i;
					last -= m;
				}
			}else{
				for (int i = A; i >= -B; i--){
					a[last] = i;
					last -= m;
				}
			}
		}else{
			//LL sum = (t + 1) * t / 2;
			//cnt -= t + 1;
			//return sum + (cnt + 1) * cnt / 2;
			if (abs(l) <= r){
				for (int i = l + cnt - 1; i >= l; i--){
					a[last] = i;
					last -= m;
				}
			}else{
				for (int i = r; i >= r - cnt + 1; i--){
					a[last] = i;
					last -= m;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		a[i] = Get();
		if (i >= m && a[i] <= a[i - m] && a[i] != INF && a[i - m] != INF)
			flag = 1;
	}
	LL ans = 0;
	for (int i = 0; i < m; i++){
		int l = -2e9, cnt = 0, last;
		for (int j = i; j < n; j += m)
		if (a[j] != INF){
			if (cnt) Get(l, a[j] - 1, cnt, last);
			cnt = 0;
			l = a[j] + 1;
		}else cnt++, last = j;
		if (cnt) Get(l, 2e9, cnt, last);
	}
	if (flag) puts("Incorrect sequence"); else{
		for (int i = 0; i < n; i++) printf("%d ", a[i]);
	}

}