#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

char c[505][505];

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
        for(int j = 1; j <= n; j++){
            cin>>c[i][j];
        }
    }
    int ans = 0;
    for(int i = 2; i < n; i++){
        for(int j = 2; j < n; j++){
            if(c[i][j] == 'X' && c[i+1][j+1] == 'X' && c[i+1][j-1] == 'X' && c[i-1][j+1] == 'X' && c[i-1][j-1] == 'X')ans++;
        }
    }
    cout<<ans<<endl;
}