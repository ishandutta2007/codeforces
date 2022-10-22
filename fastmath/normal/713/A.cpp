#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;
const int LEN = 20;

map <string, int> d;

string form(string s){
    int want = LEN - s.size();

    string add = "";
    for (int i = 0; i < want; ++i){
        add += '0';
    }

    return add + s;
}

void upd(string s, int delt){
    string mask = "";
    for (int i = 0; i < LEN; ++i){
        if ((s[i] - '0') % 2){
            mask += '1';
        }
        else{
            mask += '0';
        }
    }

    d[mask] += delt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        char type;
        string val;
        cin >> type >> val;
        if (type == '+'){
            upd(form(val), 1);
        }
        else if (type == '-'){
            upd(form(val), -1);
        }
        else if (type == '?'){
            cout << d[form(val)] << '\n';
        }
    }

    return 0;
}