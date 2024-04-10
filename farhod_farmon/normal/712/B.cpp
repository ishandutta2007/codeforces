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

void upd(char s, int &x, int &y)
{
    if(s == 'R')
        y++;
    if(s == 'L')
        y--;
    if(s == 'U')
        x--;
    if(s == 'D')
        x++;
}

string s;
int x, y;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        upd(s[i], x, y);
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            if(y <= 0)
                continue;
            y--;
            cnt++;
            if(x < 0)
                x++;
            else if(x > 0)
                x--;
            else
                y--;
        }
        if(s[i] == 'L'){
            if(y >= 0)
                continue;
            y++;
            cnt++;
            if(x < 0)
                x++;
            else if(x > 0)
                x--;
            else
                y++;
        }
        if(s[i] == 'D'){
            if(x <= 0)
                continue;
            x--;
            cnt++;
            if(y < 0)
                y++;
            else if(y > 0)
                y--;
            else
                x--;
        }
        if(s[i] == 'U'){
            if(x >= 0)
                continue;
            x++;
            cnt++;
            if(y < 0)
                y++;
            else if(y > 0)
                y--;
            else
                x++;
        }
    }
    if(x || y)
        cnt = -1;
    cout << cnt << endl;
}