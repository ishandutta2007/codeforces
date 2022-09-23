#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    bool f = true;
    for(int i = 1; i < s.size(); i++)
        if('a' <= s[i] && s[i] <= 'z')
            f = false;
    if(f){
        for(int i = 0; i < s.size(); i++){
            if('a' <= s[i] && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
            else
                s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << s << endl;
}