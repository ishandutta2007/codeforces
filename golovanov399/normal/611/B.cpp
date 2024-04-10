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

    vector<long long> a;
    for (int k = 1; k <= 61; k++){
        long long q = 0, w = 1;
        for (int i = 0; i < k; i++){
            q += w;
            w <<= 1;
        }
        w = 1;
        for (int i = 0; i < k - 1; i++){
            a.push_back(q - w);
            w <<= 1;
        }
    }
    sort(all(a));

    long long l, r;
    cin >> l >> r;
    int ans = 0;
    for (auto x : a){
        if (x >= l && x <= r)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}