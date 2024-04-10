#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n, ti;
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> ti >> s;
    int x = -1,
        y = -1;
    for(int i = 0; i < n; i++){
        if(x != -1 && y == -1 && s[i] >= '5' && s[i] != '.')
            y = i;
        if(s[i] == '.')
            x = i;
    }
    if(y == -1){
        cout << s << endl;
        return 0;
    }
    int en = y;
    bool ll = false;
    for(int i = y; i > x && ti; i--){
        if(s[i] >= '5' && s[i] <= '9'){
            ti--;
            for(int j = i - 1; j >= x; j--){
                if(j == x){
                    ll = true;
                    break;
                }
                if(s[j] != '9'){
                    s[j]++;
                    i = j + 1;
                    en = j;
                    break;
                }
            }
        }
        if(ll)
            break;
    }
    string t = "";
    if(ll){
        int i;
        for(i = x - 1; i >= 0; i--){
            if(s[i] != '9'){
                s[i]++;
                break;
            }
            s[i] = '0';
        }
        if(i >= 0){
            for(int i = 0; i < x; i++)
                t += s[i];
            cout << t << endl;
            return 0;
        }
        cout << 1;
        for(int i = 0; i < x; i++)
            cout << 0;
        cout << endl;
        return 0;
    }
    for(int i = 0; i <= en; i++)
        t += s[i];
    cout << t << endl;
}