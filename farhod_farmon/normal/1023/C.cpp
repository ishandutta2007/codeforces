#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
vector < char > v;

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if(!v.empty() && v.back() == '(' && c == ')' && n > k){
                        v.pop_back();
                        k += 2;
                }
                else{
                        v.push_back(c);
                }
        }
        for(char c: v){
                cout << c;
        }
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