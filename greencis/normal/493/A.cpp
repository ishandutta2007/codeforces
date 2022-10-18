#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,minute,num,u1[999],u2[999];
string s1,s2;
char z1[9],z2[9];

int main()
{
    cin >> s1 >> s2 >> n;
    while (n--) {
        cin >> minute >> z1 >> num >> z2;
        if (*z1 == 'h') {
            if (u1[num] == 2e9) continue;
            if (*z2 == 'y') ++u1[num];
            else u1[num] = 2;
            if (u1[num] == 2) u1[num] = 2e9, cout << s1 << " " << num << " " << minute << endl;
        } else {
            if (u2[num] == 2e9) continue;
            if (*z2 == 'y') ++u2[num];
            else u2[num] = 2;
            if (u2[num] == 2) u2[num] = 2e9, cout << s2 << " " << num << " " << minute << endl;
        }
    }

    return 0;
}