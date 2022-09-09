#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int min = 0, sum = 0, n;
    string s;
    cin >> n >> s;
    for(char c : s) min = std::min(sum += c == '-' ? -1 : 1, min);
    cout << sum - min;
    return 0;
}