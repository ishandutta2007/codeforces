#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ld eps = 1e-8;

ld compute(vector<ld> a){
    ld ret = 0.0;
    for(int i = 0; i < a.size(); i++){
        ld tmp = a[i];
        for(int j = 0; j < a.size(); j++){
            if(i != j)tmp *= (1 - a[j]);
        }
        ret += tmp;
    }
    return ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<setprecision(30);

    int n;
    ld x;
    vector<ld> a;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(abs(x - 1.0) < eps){
            cout<<1.0<<endl;
            return 0;
        }
        a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    ld ans = compute(a);
    for(int i = 1; i < n; i++){
        a.pop_back();
        ans = max(ans, compute(a));
    }
    cout<<ans<<endl;
}