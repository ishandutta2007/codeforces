#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, p, x, y, v;
    cin>>n>>k>>p>>x>>y;
    int s = 0;
    vector<int> arr;
    for(int i = 1; i <= k; i++){
        cin>>v;
        s += v;
        arr.push_back(v);
    }
    int q, rs = x - s, l = n-k;
    for(q = l; q >= 0; q--){
        if(q*y - q + l <= rs){
            break;
        }
    }
    if(q == -1){
        cout<<-1<<endl;
    }else{
        for(int i = 1; i <= q; i++){
            arr.push_back(y);
        }
        for(int i = 1; i <= l-q; i++){
            arr.push_back(1);
        }
        sort(arr.begin(), arr.end());
        if(arr[n/2] < y){
            cout<<-1<<endl;
        }else{
            for(int i = 1; i <= q; i++){
                cout<<y<<" ";
            }
            for(int i = 1; i <= l-q; i++){
                cout<<1<<" ";
            }
        }
    }
}