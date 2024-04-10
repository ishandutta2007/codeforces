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

bool f(string s)
{
    if(s[0] != 'R')
        return false;
    if(s[1] <= 'Z' && 'A' <= s[1])
        return false;
    for(int i = 2; i < s.size(); i++){
        if(s[i] == 'C')
            return true;
    }
    return false;
}

int get(string s, int t)
{
    int x = 0,
        b = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R' && t == 1)
            b = 1;
        if(s[i] == 'C' && t == 2)
            b = 1;
        if(s[i] == 'C' && t == 1)
            break;
        if(s[i] <= '9' && '0' <= s[i] && b)
            x = x * 10 + s[i] - '0';
    }
    return x;
}



int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int x, y;
        if(f(s)){
            x = get(s, 1);
            y = get(s, 2);
            string t = "";
            while(y){
                t += char('A' + (y - 1) % 26);
                y = (y - 1) / 26;
            }
            reverse(t.begin(), t.end());
            cout << t << x << endl;
        }
        else{
            string t = "";
            int x = 0, y = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] <= 'Z' && 'A' <= s[i])
                    t += s[i];
                else
                    x = x * 10 + s[i] - '0';
            }
            for(int i = 0; i < t.size(); i++)
                y = y * 26 + t[i] - 'A' + 1;
            cout << 'R' << x << 'C' << y << endl;
        }
    }
}