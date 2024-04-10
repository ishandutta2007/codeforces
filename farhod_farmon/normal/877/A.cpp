#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

string s;
string t[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

void solve()
{
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
                for(int j = 0; j < 5; j++){
                        bool m = true;
                        for(int h = 0; h < t[j].size(); h++){
                                if(i + h == s.size() || s[i + h] != t[j][h]){
                                        m = false;
                                        break;
                                }
                        }
                        cnt += m;
                }
        }
        if(cnt == 1){
                cout << "YES\n";
        }
        else{
                cout << "NO\n";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}