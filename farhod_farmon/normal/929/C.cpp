#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long C(int n, int k)
{
        if(k > n){
                return 0;
        }
        long long c = 1;
        for(int i = 0; i < k; i++){
                c *= n - i;
        }
        for(int i = 0; i < k; i++){
                c /= i + 1;
        }
        return c;
}

int s[N];
int a[N];
int b[N];
int c[N];

void solve()
{
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        for(int i = 0; i < l1; i++){
                int x;
                cin >> x;
                a[x]++; s[x] = 1;
        }
        for(int i = 0; i < l2; i++){
                int x;
                cin >> x;
                b[x]++; s[x] = 2;
        }
        for(int i = 0; i < l3; i++){
                int x;
                cin >> x;
                c[x]++; s[x] = 3;
        }
        for(int i = 1; i < N; i++){
                a[i] += a[i - 1];
                b[i] += b[i - 1];
                c[i] += c[i - 1];
        }
        long long ans = 0;
        for(int i = 1; i * 2 < N; i++){
                int ga = a[i * 2] - a[i],
                    gb = b[i * 2] - b[i],
                    gc = c[i * 2] - c[i];
                if(s[i] == 1){
                        ans += C(ga, 0) * C(gb, 2) * C(gc, 3);
                }
                else if(s[i] == 2){
                        ans += C(ga, 1) * C(gb, 1) * C(gc, 3);
                }
                else if(s[i] == 3){
                        ans += C(ga, 1) * C(gb, 2) * C(gc, 2);
                }
        }
        cout << ans << "\n";
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