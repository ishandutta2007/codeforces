#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    int cur = 0;
    int mx = 0;
    for (int i = 1; i < n - 1; i++){
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
            cur++;
        else
            cur = 0;
        mx = max(mx, cur);
    }
    printf("%d\n", (mx + 1) / 2);
    cur = 0;
    for (int i = 1; i < n - 1; i++){
        if (a[i] != a[i - 1] && a[i] != a[i + 1]){
            if (cur == 0)
                cur = i;
        } else {
            if (cur){
                for (int j = 0; cur + j <= i - 1 - j; j++){
                    a[cur + j] = a[cur - 1];
                    a[i - 1 - j] = a[i];
                }
            }
            cur = 0;
        }
    }
    if (cur){
        for (int j = 0; cur + j <= n - 2 - j; j++){
            a[cur + j] = a[cur - 1];
            a[n - 2 - j] = a[n - 1];
        }
    }
    for (auto x : a)
        printf("%d ", x);
    puts("");

    return 0;
}