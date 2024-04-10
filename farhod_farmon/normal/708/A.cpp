#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

string s;
char o[200];

int main()
{
    cin >> s;
    for(char c = 'b'; c <= 'z'; c++)
        o[c] = c - 1;
    o['a'] = 'z';
    bool b = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] > o[s[i]]){
            b = true;
            while(i < s.size() && s[i] > o[s[i]]){
                s[i] = o[s[i]];
                i++;
            }
        }
        if(b)
            break;
    }
    if(!b){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == o[s[i]]){
                b = true;
                break;
            }
        }
    }
    if(!b){
        s[s.size() - 1] = o[s[s.size() - 1]];
    }
    cout << s << endl;
}