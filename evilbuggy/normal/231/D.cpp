#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int a[6];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, z, x1, y1, z1;
    cin>>x>>y>>z;
    cin>>x1>>y1>>z1;
    for(int i = 0; i < 6; i++){
        cin>>a[i];
    }
    int sum = 0;
    if(y < 0){
        sum += a[0];
    }
    if(y > y1){
        sum += a[1];
    }
    if(z < 0){
        sum += a[2];
    }
    if(z > z1){
        sum += a[3];
    }
    if(x < 0){
        sum += a[4];
    }
    if(x > x1){
        sum += a[5];
    }
    cout<<sum<<endl;
}