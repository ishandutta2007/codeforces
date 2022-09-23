#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
vector < char > a, b;

void solve()
{
        cin >> n;
        int x = 1, y = 1;
        for(int i = 1; i < n; i++){
                string s;
                cout << "? " << x << " " << y + 1 << " " << n << " " << n << endl;
                cin >> s;
                if(s == "YES"){
                        y++;
                        a.push_back('R');
                }
                else{
                        x++;
                        a.push_back('D');
                }
        }
        x = n, y = n;
        for(int i = 1; i < n; i++){
                string s;
                cout << "? " << 1 << " " << 1 << " " << x - 1 << " " << y << endl;
                cin >> s;
                if(s == "YES"){
                        x--;
                        b.push_back('D');
                }
                else{
                        y--;
                        b.push_back('R');
                }
        }
        reverse(b.begin(), b.end());
        cout << "! ";
        for(char c: a){
                cout << c;
        }
        for(char c: b){
                cout << c;
        }
        cout << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}