#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

string tostr(int x){
    string res = "";
    while (x){
        res = ((char)('0' + x % 10)) + res;
        x /= 10;
    }
    if (res == "")
        res = "0";
    return res;
}

int main(){

    int n;
    cerr << tostr(123) << "\n";
    long long m;
    cin >> n >> m;
    m--;
    string ans = tostr(n);
    for (int i = 0; i < n - 1; i++){
        if (m % 2){
            ans = ans + " " + tostr(n - i - 1);
        } else {
            ans = tostr(n - i - 1) + " " + ans;
        }
        m >>= 1;
    }
    cout << ans << "\n";

    return 0;
}