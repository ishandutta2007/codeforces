#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 32;
int get(){
    string s;
    cin >> s;
    int res = s[0] - '0';
    if(s[1] == 'm') return res + 200;
    if(s[1] == 'p') return res + 100;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int A[3] = {get(), get(), get()};
    sort(A, A + 3);
    if(A[0] + 1 == A[1] and A[1] + 1 == A[2]) cout << 0;
    else if(A[0] == A[1] and A[1] == A[2]) cout << 0;
    else if(A[1] - A[0] <= 2 or A[2] - A[1] <= 2) cout << 1;
    else cout << 2;
    return 0;
}