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

string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    if(s.size() < 26){
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 0; i + 25 < s.size(); i++){
        bool used[26];
        for(int j = 0; j < 26; j++)
            used[j] = false;
        bool can = true;
        for(int j = 0; j < 26; j++){
            if(s[i + j] == '?')
                continue;
            if(used[s[i + j] - 'A'])
                can = false;
            used[s[i + j] - 'A'] = true;
        }
        if(!can){
            if(i + 26 == s.size()){
                cout << -1 << "\n";
                return 0;
            }
            continue;
        }
        for(int j = 0; j < 26; j++){
            if(s[i + j] != '?')
                continue;
            s[i + j] = 'A';
            while(used[s[i + j] - 'A'])
                s[i + j]++;
            used[s[i + j] - 'A'] = true;
        }
        break;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '?')
            s[i] = 'A';
        cout << s[i];
    }
}