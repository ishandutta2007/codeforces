#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char a[305][305];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    for(int rad = 1; rad <= 150; rad++){
        if(2*rad + 1 > min(n, m))break;
        for(int i = rad + 1; i <= n - rad; i++){
            for(int j = rad + 1; j <= m - rad; j++){
                k -= (a[i][j]=='*')&&(a[i+rad][j]=='*')&&(a[i-rad][j]=='*')&&(a[i][j-rad]=='*')&&(a[i][j+rad]=='*');
                if(k == 0){
                    cout<<i<<" "<<j<<endl;
                    cout<<i - rad<<" "<<j<<endl;
                    cout<<i + rad<<" "<<j<<endl;
                    cout<<i<<" "<<j - rad<<endl;
                    cout<<i<<" "<<j + rad<<endl;
                    exit(0);
                }
            }
        }
    }
    cout<<-1<<endl;
}