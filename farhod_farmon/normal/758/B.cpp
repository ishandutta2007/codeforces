#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 500300;
const long long mod = 1e15 + 3;

using namespace std;

string s;
int a[4];
int ans[4];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '!')
            ans[i % 4]++;
        else if(s[i] == 'R')
            a[0] = i % 4;
        else if(s[i] == 'B')
            a[1] = i % 4;
        else if(s[i] == 'Y')
            a[2] = i % 4;
        else if(s[i] == 'G')
            a[3] = i % 4;
    }
    for(int i = 0; i < 4; i++)
        cout << ans[a[i]] << " ";
}