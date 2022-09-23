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
    cin >> s;
    int cnt = 0;
    char last = -1;
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == last){
            h++;
            if(h > 5){
                h = 1;
                cnt++;
            }
        }
        else{
            h = 1;
            cnt++;
        }
        last = s[i];
    }
    cout << cnt << endl;
}