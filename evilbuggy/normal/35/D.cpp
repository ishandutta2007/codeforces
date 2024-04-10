#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, x;
    cin>>n>>x;
    int c[n+1];
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        c[i] *= (n+1-i);
    }
    sort(c + 1, c + n + 1);
    int i = 1;
    while(i <= n){
        if(c[i] > x)break;
        x -= c[i];
        i++;
    }
    i--;
    cout<<i<<endl;
}