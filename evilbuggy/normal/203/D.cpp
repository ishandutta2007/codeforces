#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld reduce(ld x, ld a){
    bool rev = false;
    if(x < 0){
        x = -x;
    }
    for(int i = 0; i < 1000000; i++){
        if(a*i <= x && x < a*i + a){
            if(rev)return a*i + a - x;
            return x - a*i;
        }
        rev ^= true;
    }
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

    ld a, b, m;
    ld vx, vy, vz;
    cin>>a>>b>>m;
    cin>>vx>>vy>>vz;
    ld t = abs(m/vy);
    ld x = a/2 + vx*t;
    ld z = vz*t;
    x = reduce(x, a);
    z = reduce(z, b);
    cout<<x<<" "<<z<<endl;
}