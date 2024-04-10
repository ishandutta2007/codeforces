#include <bits/stdc++.h>

using namespace std;

int n, b, a[110], o, ans;
priority_queue<int> pq;

int main() {
    scanf("%d %d", &n, &b);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if(i && 2*o == i)
            pq.push(-abs(a[i] - a[i-1]));

        if(a[i] % 2) o++;
    }

    while(!pq.empty() && -pq.top() <= b) {
        b += pq.top(); pq.pop();
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}