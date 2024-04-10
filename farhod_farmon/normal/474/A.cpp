#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

string s[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
string t;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    char c;
    cin >> c >> t;
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < 3; j++){
            for(int h = 0; h < s[j].size(); h++){
                if(s[j][h] == t[i]){
                    if(c == 'L')
                        t[i] = s[j][h + 1];
                    else
                        t[i] = s[j][h - 1];
                    break;
                }
            }
        }
    }
    cout << t << endl;
}