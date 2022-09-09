#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        int sum = 0;
        for(int &x : a) sum += x;
        int m = *max_element(a.begin(), a.end());
        if(m * 2 > sum) cout << "T\n";
        else cout << (sum & 1 ? "T\n" : "HL\n");
    }
    cout.tie(nullptr);
    return 0;
}