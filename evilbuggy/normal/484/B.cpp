#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const int maxn = 1000005;
int a[maxn];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a, 0, sizeof(a));
    int n, x;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        a[x] = x;
    }
    for(int i = 1; i < maxn; i++){
        a[i] = max(a[i], a[i-1]);
    }
    int ans = 0;
    for(int i = 2; i < maxn; i++){
        if(a[i] != i)continue;
        for(int l = i; l < maxn; l += i){
            int r = min(l + i, maxn);
            if(ans < a[r-1] - l){
                ans = a[r-1] - l;
            }
        }
    }
    cout<<ans<<endl;
}