#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (s[0] == '<' && s[n - 1] == '>' && t[0] == 'v' && t[m - 1] == '^'){
        cout << "YES\n";
    } else
    if (s[0] == '>' && s[n - 1] == '<' && t[0] == '^' && t[m - 1] == 'v'){
        cout << "YES\n";
    } else
    cout << "NO\n";

    return 0;
}