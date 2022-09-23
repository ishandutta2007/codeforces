#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
string s, t;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s >> t;
    int l = 0,
        r = n - 1;
    while(s[l] == t[l])
        l++;
    while(s[r] == t[r])
        r--;
    if(l == r){
        cout << 2 << endl;
        return 0;
    }
    bool b1 = true,
         b2 = true;
    for(int i = l; i < r; i++){
        if(s[i] != t[i + 1])
            b1 = false;
        if(t[i] != s[i + 1])
            b2 = false;
    }
    cout << b1 + b2 << endl;
}