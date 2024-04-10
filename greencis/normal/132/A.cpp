#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[105];

int bitrev(int num) {
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        ans <<= 1;
        ans |= (num & 1);
        num >>= 1;
    }
    return ans;
}

int main()
{
    gets(s);
    int prev = 0;
    for (int i = 0; s[i]; ++i) {
        int curnum = bitrev(s[i]);
        int ans = (prev - curnum + 512) % 256;
        prev = curnum;
        cout << ans << endl;
    }

    return 0;
}