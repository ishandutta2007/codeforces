#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cnt(26);
    int n;
    LL T;
    string S;
    cin >> n >> T >> S;
    if(n == 1){
        cout << ((1LL << (S[0] - 'a')) == T ? "Yes" : "No");
        return 0;
    }
    for(int i = 0; i + 2 < n; i += 1) cnt[S[i] - 'a'] += 1;
    T -= 1LL << (S[n - 1] - 'a');
    T += 1LL << (S[n - 2] - 'a');
    for(int i = 25; i >= 0; i -= 1)
        for(int j = 0; j < cnt[i]; j += 1)
            if(abs(T - (1LL << i)) < abs(T + (1LL << i))) T -= 1LL << i;
            else T += 1LL << i;
    cout << (T ? "No" : "Yes");
    return 0;
}