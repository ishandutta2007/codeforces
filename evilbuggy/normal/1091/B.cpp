#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

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
    ll x, y, sx = 0, sy = 0;
    for(int i = 1; i <= 2*n; i++){
        cin>>x>>y;
        sx += x;
        sy += y;
    }
    cout<<sx/n<<" "<<sy/n<<endl;

}