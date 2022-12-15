#include <bits/stdc++.h>
using namespace std;

int main() {
    char color[105];
    int arr[30], k, n;
    bool end = false;
    memset(arr, 0, sizeof(arr));
    scanf("%d %d %s", &n, &k, color);
    for(int i = 0; i < n; i++) {
        if(++arr[color[i] - 97] > k) {
            end = true;
            break;
        }
    }
    if(end) {
        puts("NO");
    } else {
        puts("YES");
    }
	return 0;
}