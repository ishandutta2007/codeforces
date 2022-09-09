#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        multiset<int> s;
        int A = 0, B = 0;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            s.insert(x);
        }
        while(s.count(A)){
            s.erase(s.find(A));
            A += 1;
        }
        while(s.count(B)){
            s.erase(s.find(B));
            B += 1;
        }
        cout << A + B << "\n";
    }
    return 0;
}