#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 1000000ll * 1000000ll * 1000000ll;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int q;
long long s[N];
long long k[N];

long long get(long long x)
{
        long long cnt = 0;
        while(x > 1){
                cnt++;
                x /= 2;
        }
        return cnt;
}

void solve()
{
        cin >> q;
        while(q--){
                long long t, x, d;
                cin >> t >> x;
                if(t == 1){
                        cin >> d;
                        d = - d;
                        long long g = get(x);
                        k[g] = (k[g] + d) % (1ll << g);
                        if(k[g] < 0)k[g] += (1ll << g);
                }
                else if(t == 2){
                        cin >> d;
                        long long g = get(x);
                        s[g] = (s[g] + d) % (1ll << g);
                        if(s[g] < 0)s[g] += (1ll << g);
                }
                else{
                        vector < long long > v;
                        long long g = get(x);
                        v.push_back(x);
                        for(long long i = g; i > 0; i--){
                                long long j = ((x - (1ll << i)) - k[i] + s[i]) % (1ll << i);
                                if(j < 0) j += (1ll << i);
                                x = (k[i - 1] + j / 2) % (1ll << (i - 1)) + (1ll << (i - 1));
                                v.push_back(x);
                        }
                        sort(v.begin(), v.end());
                        for(int i = v.size() - 1; i >= 0; i--){
                                cout << v[i] << " ";
                        }
                        cout << "\n";
                }
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