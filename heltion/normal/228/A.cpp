#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> s;
    for(int i = 0, x; i < 4; i += 1){
        cin >> x;
        s.insert(x);
    }
    cout << 4 - s.size();
    return 0;
}