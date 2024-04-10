#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    string s;
    cin >> s;
    string t = "CODEFORCES";
    int qw = 0;
    for (int i = 0; i < s.length() && i < t.length() && s[i] == t[i]; i++){
        qw++;
    }
    reverse(all(s));
    reverse(all(t));
    for (int i = 0; i < s.length() && i < t.length() && s[i] == t[i]; i++){
        qw++;
    }
    if (qw >= t.length()){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}