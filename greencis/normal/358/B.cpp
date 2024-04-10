#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s1,s2,s;

int main()
{
    cin >> n;
    while (n--) {
        cin >> s;
        s1 += "<3" + s;
    }
    s1 += "<3";
    cin >> s2;
    int ai = 0, bi = 0;
    while (ai < s1.size() && bi < s2.size()) {
        if (s1[ai] == s2[bi]) ++ai, ++bi;
        else ++bi;
    }
    if (ai == s1.size()) cout << "yes";
    else cout << "no";

    return 0;
}