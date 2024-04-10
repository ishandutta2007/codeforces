#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int i;
    cin >> i;
    return i;
}
void answer(int p){
    cout << "! " << p << endl;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int L = 1, R = n;
    while(L < R){
        int M = (L + R) / 2;
        int i = query(L, R);
        if(L + 1 == R) answer(L + R - i);
        if(i <= M){
            if(L == M){
                L = M + 1;
                continue;
            }
            int j = query(L, M);
            if(i == j) R = M;
            else L = M + 1;
        }
        else{
            if(M + 1 == R){
                R = M;
                continue;
            }
            int j = query(M + 1, R);
            if(i == j) L = M + 1;
            else R = M;
        }
    }
    cout << "! " << L << endl;
    return 0;
}