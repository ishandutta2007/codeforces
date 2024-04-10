#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 1000010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

long long f[N];
string S = "What are you doing at the end of the world? Are you busy? Will you save us?";
string p1 = "What are you doing while sending 0";
string p2 = "0? Are you busy? Will you send 0";
string p3 = "0?";

char get(string s, int k)
{
        if(s[k - 1] == '0'){
                return '"';
        }
        else{
                return s[k - 1];
        }
}

char go(int n, long long k)
{
        if(k > f[n]){
                return '.';
        }
        if(n == 0){
                return get(S, k);
        }
        if(k <= p1.size()){
                return get(p1, k);
        } k -= p1.size();
        if(k <= f[n - 1]){
                return go(n - 1, k);
        } k -= f[n - 1];
        if(k <= p2.size()){
                return get(p2, k);
        } k -= p2.size();
        if(k <= f[n - 1]){
                return go(n - 1, k);
        } k -= f[n - 1];
        return get(p3, k);
}

void solve()
{
        long long INF = 2e18;
        f[0] = S.size();
        for(int i = 1; i < N; i++){
                f[i] = f[i - 1] + f[i - 1] + p1.size() + p2.size() + p3.size();
                if(f[i] > INF){
                        f[i] = INF;
                }
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                long long n, k;
                cin >> n >> k;
                cout << go(n, k);
        }
        cout << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}