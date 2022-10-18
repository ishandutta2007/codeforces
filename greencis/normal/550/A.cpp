#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

string s,ss;

int main()
{
    cin >> s;
    ss = s;
    bool good = false;
    if (ss.find("AB") != -1) {
        int qqq = ss.find("AB");
        ss.erase(qqq,2);
        ss.insert(qqq, "#");
        if (ss.find("BA") != -1) good = true;
    }
    ss = s;
    if (ss.find("BA") != -1) {
        int qqq = ss.find("BA");
        ss.erase(qqq,2);
        ss.insert(qqq, "#");
        if (ss.find("AB") != -1) good = true;
    }
    if (good) cout << "YES";
    else cout << "NO";

    return 0;
}