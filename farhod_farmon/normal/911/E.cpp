#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];
set < int > f;
vector < int > s;

void solve()
{
        int x = 1;
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                cin >> a[i];
                s.push_back(a[i]);
                while(!s.empty() && s.back() == x){
                        s.pop_back();
                        x++;
                }
        }
        for(int x: s){
                f.insert(x);
        }
        while(!s.empty()){
                int y = *f.begin();
                f.erase(f.begin());
                if(s.back() != y){
                        cout << -1 << "\n";
                        return;
                }
                s.pop_back();
                for(int i = y - 1; i >= x; i--){
                        k++;
                        a[k] = i;
                }
                x = y + 1;
        }
        for(int i = n; i >= x; i--){
                k++;
                a[k] = i;
        }
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
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