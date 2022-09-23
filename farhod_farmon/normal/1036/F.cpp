#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

unsigned long long mx = 1000000ll * 1000000ll * 1000000ll + 1;
vector < unsigned long long > v[100];
map < unsigned long long, bool > used;

unsigned long long f(unsigned long long x, int g)
{
        unsigned long long ff = x;
        for(int i = 1; i < g; i++){
                if(ff > mx / x){
                        return mx + 1;
                }
                ff *= x;
        }
        return ff;
}

bool ez(unsigned long long x)
{
        unsigned long long l = 1, r = 1e9;
        while(l < r){
                unsigned long long m = (l + r) / 2;
                if(m * m < x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        if(l * l == x){
                return false;
        }
        return true;
}

unsigned long long f(unsigned long long x)
{
        unsigned long long cnt = 1, tr = 1e9;
        while(cnt < tr){
                unsigned long long m = (cnt + tr) / 2;
                if(m * m < x){
                        cnt = m + 1;
                }
                else{
                        tr = m;
                }
        }
        if(cnt * cnt > x){
                cnt--;
        }
        for(int i = 3; i < 100; i++){
                int l = 0, r = v[i].size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(v[i][m + 1] <= x){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                cnt += l;
        }
        return cnt;
}

void solve()
{
        for(int i = 3; i < 100; i++){
                v[i].push_back(0);
                unsigned long long x = 2, y = f(x, i);
                if(y > mx){
                        break;
                }
                while(y < mx){
                        if(!used[y] && ez(y)){
                                used[y] = 1;
                                v[i].push_back(y);
                        }
                        x++;
                        y = f(x, i);
                }
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                unsigned long long l, r;
                cin >> r;
                cout << r - f(r) << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}