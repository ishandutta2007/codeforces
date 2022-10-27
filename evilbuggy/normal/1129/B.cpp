#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 1000000;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    ll k;
    cin>>k;
    cout<<2000<<endl;
    cout<<-1<<" ";
    int s = k + 2000;
    for(int i = 2; i <= 2000; i++){
        if(s > maxn){
            cout<<maxn<<" ";
            s -= maxn;
        }else{
            cout<<s<<" ";
            s = 0;
        }
    }
}