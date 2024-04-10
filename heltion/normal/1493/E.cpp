#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string l, r;
    cin >> n >> l >> r;
    if(r == "0"){
        cout << "0";
        return 0;
    }
    if(l[0] != '1'){
        cout << string(n, '1');
        return 0;
    }
    if(r.back() == '0'){
        string tmp = l;
        tmp[n - 2] += 1;
        for(int i = n - 2; i > 0; i -= 1){
            if(tmp[i] <= '1') break;
            else{
                tmp[i] = '0';
                tmp[i - 1] += 1;
            }
        }
        if(tmp <= r) r.back() += 1;
    }
    cout << r;
    return 0;
}