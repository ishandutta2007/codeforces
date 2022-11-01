#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, a[N], c[N], cnt[26], len[26], pos[26][N];

char s[N], g[N];

LL ans = 0;

void merge(int l, int mid, int r){
    for(int k = l, i = l, j = mid + 1; k <= r; k++){
        if(j > r || (i <= mid && a[i] <= a[j])) c[k] = a[i++];
        else c[k] = a[j++], ans += (mid - i + 1);
    }
    for(int i = l; i <= r; i++) a[i] = c[i];
    return;
}
void mergeSort(int l, int r){
    if(l >= r) return; 
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
    return; 
}

int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++)
		g[i] = s[n - i + 1];
	for (int i = 1; i <= n; i++) {
		pos[g[i] - 'a'][++len[g[i] - 'a']] = i;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = pos[s[i] - 'a'][++cnt[s[i] - 'a']];
	}
	mergeSort(1, n);
	printf("%lld\n", ans);
	return 0;
}