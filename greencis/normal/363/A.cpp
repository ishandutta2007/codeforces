#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s[10] = {
"O-|-OOOO",
"O-|O-OOO",
"O-|OO-OO",
"O-|OOO-O",
"O-|OOOO-",
"-O|-OOOO",
"-O|O-OOO",
"-O|OO-OO",
"-O|OOO-O",
"-O|OOOO-",
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    do {
        cout << s[n % 10] << endl;
        n /= 10;
    } while (n);

    return 0;
}