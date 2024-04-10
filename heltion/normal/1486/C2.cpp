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
    int s = query(1, n);
    int x;
    if(s == 1) x = -1;
    else x = query(1, s);
    if(x == s){
        int L = 1, R = s - 1;
        while(L < R){
            int M = (L + R + 1) / 2;
            int y = query(M, s);
            if(y == s) L = M;
            else R = M - 1;
        }
        answer(L);
    }
    else{
        int L = s + 1, R = n;
        while(L < R){
            int M = (L + R) / 2;
            int y = query(s, M);
            if(y == s) R = M;
            else L = M + 1;
        }
        answer(L);
    }
    return 0;
}
//3 2 4 1 5