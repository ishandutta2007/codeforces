#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int l;
vector < int > v;

int f(int n)
{
        int cnt = 0;
        for(int i = 1; i < (1 << l); i++){
                int x = 1;
                for(int j = 0; j < l; j++){
                        if(i & (1 << j)){
                                x *= v[j];
                        }
                }
                if(__builtin_popcount(i) % 2){
                        cnt += n / x;
                }
                else{
                        cnt -= n / x;
                }
        }
        return n - cnt;
}

int n, p, k;

void solve()
{
        cin >> n >> p >> k;
        v.clear();
        int x = p;
        for(int i = 2; i * i <= p; i++){
                if(p % i == 0){
                        v.push_back(i);
                }
                while(p % i == 0){
                        p /= i;
                }
        }
        if(p > 1){
                v.push_back(p);
        }
        l = v.size();
        int l = 1, r = 1e9, g = f(n);
        while(l < r){
                int m = (l + r) / 2;
                if(f(m) - g < k){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        cout << l << "\n";
}

bool mtest = true; int main()
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