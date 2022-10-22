#include<bits/stdc++.h>
using namespace std;

int n, k;
long long a[400000];
long long ans;
priority_queue<long long> pQ;

int main() {
    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i=n-1; i>=0; i--) {
        a[i] += a[i+1];
        if(i > 0) pQ.push(a[i]);
    }

    ans = a[0];
    for(int i=1; i<k; i++) {
        ans += pQ.top();
        pQ.pop();
    }

    printf("%lld", ans);
}