#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s;

int main()
{
    scanf("%d",&n);
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        bool freda = false, rainbow = false;
        if (s.size() >= 5) {
            if (s.substr(s.size() - 5, 5) == "lala.") freda = true;
            if (s.substr(0, 5) == "miao.") rainbow = true;
        }
        if (freda && !rainbow) puts("Freda's");
        else if (!freda && rainbow) puts("Rainbow's");
        else puts("OMG>.< I don't know!");
    }
    return 0;
}