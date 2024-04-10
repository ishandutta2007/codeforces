#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1000;
int a[maxn + 1];
void work(){
    int N, P = 0;
    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> a[i];
        if(a[i] == 1) P = i;
    }
    for(int i = 1; i + 1 < P; i += 1)
        if(a[i] < a[i + 1]){
            cout << "YES\n" << i << " " << i + 1 << " " << P << "\n";
            return;
        }
    for(int i = P + 1; i < N; i += 1)
        if(a[i] > a[i + 1]){
            cout << "YES\n" << P << " " << i << " " << i + 1 << "\n";
            return;
        }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1) work();
    return 0;
}