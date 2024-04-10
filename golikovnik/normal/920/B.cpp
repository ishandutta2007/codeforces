#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

struct data {
    int l;
    int r;
    int pos;
} arr[1004];

int ans[1004];

bool cmp(data a, data b) {
    if (a.l == b.l) 
        return a.pos < b.pos;
    return a.l < b.l;
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, t = 0;
        scanf("%d", &n);
        for(int i = 0;i < n;i++) {
            scanf("%d %d", &arr[i].l, &arr[i].r);
            arr[i].pos = i;
        }
        sort(arr, arr + n, cmp);
        for(int i = 0;i < n;i++) {
            while(t < arr[i].l)
                t++;
            if(arr[i].r < t) {
                ans[arr[i].pos] = 0;
                continue;
            }
            ans[arr[i].pos] = t;
            t++;
        }
        for(int i = 0;i < n;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}