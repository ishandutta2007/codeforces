#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

string s;

bool gg()
{
        bool f1 = 0, f2 = 0, f3 = 0;
        for(int i = 0; i < s.size(); i++){
                if('A' <= s[i] && s[i] <= 'Z'){
                        f1 = 1;
                }
                else if('a' <= s[i] && s[i] <= 'z'){
                        f2 = 1;
                }
                else{
                        f3 = 1;
                }
        }
        if((f1 & f2 & f3) == 1){
                cout << s << "\n";
                return true;
        }
        return false;
}

void solve()
{
        cin >> s;
        if(gg())return;
        for(int i = 0; i < s.size(); i++){
                char c1 = s[i];
                s[i] = 'a'; if(gg())return;
                s[i] = 'A'; if(gg())return;
                s[i] = '1'; if(gg())return;
                s[i] = c1;
        }
        for(int i = 0; i + 1 < s.size(); i++){
                char c1 = s[i], c2 = s[i + 1];
                s[i] = 'a'; s[i + 1] = 'A'; if(gg())return;
                s[i] = 'a'; s[i + 1] = '1'; if(gg())return;
                s[i] = 'A'; s[i + 1] = '1'; if(gg())return;
                s[i] = c1; s[i + 1] = c2;
        }
        for(int i = 0; i + 2 < s.size(); i++){
                s[i] = '1';
                s[i + 1] = 'a';
                s[i + 2] = 'A';
                if(gg())return;
        }
}

bool mtest = true; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}