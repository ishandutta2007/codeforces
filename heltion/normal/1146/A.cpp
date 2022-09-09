#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    cout << min((int)count(s.begin(), s.end(), 'a') * 2 - 1, (int)s.size());
    return 0;
}