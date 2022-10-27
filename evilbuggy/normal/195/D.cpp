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

    int n, k, b;
    cin>>n;
    set<pair<int,int> >arr;
    while(n--){
        cin>>k>>b;
        if(k == 0)continue;
        // cout<<k<<" "<<b<<endl;
        int tmp = __gcd(abs(k), abs(b));
        k /= tmp;
        b /= tmp;
        if(b > 0)arr.insert({b, k});
        else if(b == 0)arr.insert({0, 0});
        else arr.insert({-b, -k});
    }
    cout<<arr.size()<<endl;
}