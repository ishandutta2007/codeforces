#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll x[100005];

bool check(ll x){
    if(x < 0)return false;
    ll tmp = sqrt(x + .0);
    if(tmp*tmp == x) return true;
    tmp++;
    if(tmp*tmp == x) return true;
    return false;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    memset(x, 0, sizeof(x));
    int n;
    cin>>n;
    for(int i = 2; i <= n; i += 2){
        cin>>x[i];
    }
    ll sq = 0;
    ll sum = 0;
    for(int i = 2; i <= n; i += 2){
        while(sq < 1e7 && (!check(sq*sq - x[i]) || sum + x[i] >= sq*sq))sq++;
        x[i - 1] = sq*sq - sum - x[i];
        sum += x[i] + x[i-1];
    }
    sum = 0;
    for(int i = 1; i <= n; i++){
        if(x[i] <= 0 || !check(sum)){
            cout<<"No"<<endl;
            exit(0);
        }
        sum += x[i];
    }
    cout<<"Yes"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<x[i]<<" ";
    }
}