#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
vector < int > v;

int f(vector < int > g)
{
        int s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i++){
                s1 += i;
        }
        for(int x: g){
                s2 += x;
        }
        s1 -= s2;
        return abs(s1 - s2);
}

void solve()
{
        cin >> n;
        vector < int > v;
        if(n % 2){
                v.push_back(1);
                for(int i = 1; i <= n / 4; i++){
                        v.push_back(2 * i);
                        v.push_back(n - 2 * (i - 1));
                }
                if((n / 2) % 2){
                        v.push_back(n / 2 + 1);
                }
        }
        else{
                for(int i = 0; i < n / 4; i++){
                        v.push_back(2 * i + 1);
                        v.push_back(n - 2 * i);
                }
                if((n / 2) % 2){
                        v.push_back(n / 2);
                }
        }
        cout << f(v) << "\n";
        cout << v.size() << " ";
        for(int x: v){
                cout << x << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}