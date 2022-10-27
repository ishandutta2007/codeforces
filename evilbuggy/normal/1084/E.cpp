#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, k;
    cin>>n>>k;
    string l, r;
    cin>>l>>r;
    ll cnt = 1, ans = 0;
    for(int i = 0; i < n; i++){
        ll tcnt = (cnt - 2)*2;
        if(l[i] == 'a')tcnt += 2;
        else tcnt += 1;
        if(r[i] == 'b')tcnt += 2;
        else tcnt += 1;
        cnt = tcnt;
        if(cnt > k){
            ans += 1LL*(n-i)*k;
            break;
        }else{
            ans += cnt;
        }
    }
    cout<<ans<<endl;
}