#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

set<pair<int,int> > arr;
int a[100005], c[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        arr.insert({c[i], i});
    }
    int t, d;
    while(m--){
        cin>>t>>d;
        ll ans = 0;
        if(a[t] != 0){
            if(a[t] >= d){
                ans = 1LL*d*c[t];
                a[t] -= d;
                d = 0;
                if(a[t] == 0){
                    arr.erase({c[t], t});
                }
            }else{
                ans = 1LL*a[t]*c[t];
                d -= a[t];
                a[t] = 0;
                arr.erase({c[t], t});
            }
        }
        while(d > 0 && !arr.empty()){
            pair<int, int> y = *(arr.begin());
            t = y.second;
            if(a[t] >= d){
                ans += 1LL*d*c[t];
                a[t] -= d;
                d = 0;
                if(a[t] == 0){
                    arr.erase(y);
                }
            }else{
                ans += 1LL*a[t]*c[t];
                d -= a[t];
                a[t] = 0;
                arr.erase(y);
            }
        }
        if(d == 0)cout<<ans<<endl;
        else cout<<0<<endl;
    }
}