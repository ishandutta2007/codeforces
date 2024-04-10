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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    deque<int> dq;
    for(int i = n - 1; i >= 0; i--){
        if(i&1)dq.push_front(a[i]);
        else dq.push_back(a[i]);
    }
    for(int i = 0; i < n; i++){
        cout<<dq[i]<<" ";
    }
}