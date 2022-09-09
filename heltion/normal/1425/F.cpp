#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int P[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 2; i <= N; i += 1){
        cout << "? " << 1 << " " << i << endl;
        cin >> P[i];
    }
    cout << "? 2 3" << endl;
    cin >> P[1];
    cout << "! ";
    for(int i = 1; i <= N; i += 1){
        if(i == 1) cout << P[3] - P[1] << " ";
        else if(i == 2) cout << P[1] + P[2] - P[3] << " ";
        else cout << P[i] - P[i - 1] << " ";
    }
    return 0;
}