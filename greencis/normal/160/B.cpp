#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,slen;
    string s;
    cin>>n>>s;
    sort(s.begin(),s.begin()+n);
    sort(s.begin()+n,s.begin()+n+n);
    slen = s.length();
    bool ok = true;
    for (int i = 0; i < n; ++i) { // >
        if (s[i] <= s[i+n]) ok = false;
    }
    if (!ok) {
        ok = true;
        for (int i = 0; i < n; ++i) { // <
            if (s[i] >= s[i+n]) ok = false;
        }
    }
    cout << (ok?"YES":"NO");
    return 0;
}