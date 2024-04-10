#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void convert(string& t){
    for(int i = 0; i < t.length(); ++i){
        if(t[i] >= 'A' && t[i] <= 'Z'){
            t[i] += 'a' - 'A';
        }
        if(t[i] == 'i' || t[i] == 'l'){
            t[i] = '1';
        }
        if(t[i] == 'o'){
            t[i] = '0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    string s, t;
    int n;
    cin >> s;
    convert(s);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> t;
        convert(t);
        if(s == t){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}