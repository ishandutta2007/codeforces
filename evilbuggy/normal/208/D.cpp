#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll p[55], a[5];
ll cnt[5];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }

    for(int i = 0; i < 5; i++){
        cin>>a[4-i];
        cnt[i] = 0;
    }

    ll ret = 0;

    for(int i = 1; i <= n; i++){
        ret += p[i];
        for(int j = 0; j < 5; j++){
            cnt[j] += ret/a[j];
            ret %= a[j];
        }
    }
    for(int i = 0; i < 5; i++){
        cout<<cnt[4-i]<<" ";
    }
    cout<<endl;
    cout<<ret<<endl;

}