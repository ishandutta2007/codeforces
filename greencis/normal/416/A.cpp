#include <iostream>
using namespace std;

int n,mn=-2e9,mx=2e9,a;
string s,ans;

int main()
{
    cin >> n;
    while (n--) {
        cin >> s >> a >> ans;
        if (ans == "N") {
            if (s == ">=") s = "<";
            else if (s == "<=") s = ">";
            else if (s == ">") s = "<=";
            else s = ">=";
        }
        if (s == ">") {
            s = ">=";
            ++a;
        } else if (s == "<") {
            s = "<=";
            --a;
        }

        if (s == ">=") {
            if (a > mx) {cout << "Impossible";return 0;}
            mn = max(a,mn);
        } else if (s == "<=") {
            if (a < mn) {cout << "Impossible";return 0;}
            mx = min(a,mx);
        }
    }

    cout << mn;

    return 0;
}