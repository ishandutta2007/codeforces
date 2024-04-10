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

    int n, x;
    cin>>n;
    deque<int> a;
    while(n--){
        cin>>x;
        x &= 1;
        if(a.empty() || a.back() != x)a.push_back(x);
        else a.pop_back();
    }
    if(a.size() > 1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}