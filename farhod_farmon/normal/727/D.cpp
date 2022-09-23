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

map < string, int > id;
vector < int > g1[7], g2[7];
int c[7];
int n;
int ans[N];

string get(int x)
{
    if(x == 1)
        return "S";
    if(x == 2)
        return "M";
    if(x == 3)
        return "L";
    if(x == 4)
        return "XL";
    if(x == 5)
        return "XXL";
    if(x == 6)
        return "XXXL";
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    for(int i = 1; i <= 6; i++)
        cin >> c[i];
    id["S"] = 1;
    id["M"] = 2;
    id["L"] = 3;
    id["XL"] = 4;
    id["XXL"] = 5;
    id["XXXL"] = 6;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ans[i] = -1;
        string s, t = "";
        cin >> s;
        bool b = false;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ','){
                g2[id[t]].pb(i);
                b = true;
                t = "";
                continue;
            }
            t += s[j];
        }
        g1[id[t]].pb(i);
    }
    for(int i = 1; i <= 6; i++){
        for(auto x: g1[i]){
            if(!c[i])
                break;
            if(ans[x] != -1)
                continue;
            ans[x] = i;
            c[i]--;
        }
        for(auto x: g2[i]){
            if(!c[i])
                break;
            if(ans[x] != -1)
                continue;
            ans[x] = i;
            c[i]--;
        }
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] == -1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << get(ans[i]) << endl;
}