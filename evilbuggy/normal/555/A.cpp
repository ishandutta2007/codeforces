#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, k, mx = 1;
    cin>>n>>k;
    for(int i = 1; i <= k; i++){
        int sz;
        cin>>sz;
        for(int j = 1; j <= sz; j++){
            cin>>a[j];
        }
        if(a[1] != 1)continue;
        for(int j = 2; j <= sz; j++){
            if(a[j] == a[j-1] + 1)mx++;
            else break;
        }
    }
    cout<<2*(n - mx) - k + 1<<endl;
}