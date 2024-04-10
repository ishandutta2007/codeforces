#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

string s, t = "";
char c[26];
int in[200];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    int st1,
        st2;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(in[s[i]]){
            int j = in[s[i]] - 1;
            st1 = j;
            st2 = 12 - (i - j - 1) / 2;
        }
        else{
            in[s[i]] = i + 1;
            t += s[i];
        }
    }
    for(int i = 0; i < 26; i++)
        c[(st2 + i) % 26] = t[(st1 + i) % 26];
    for(int i = 0; i < 13; i++)
        cout << c[i];
    cout << endl;
    for(int i = 25; i >= 13; i--)
        cout << c[i];
}