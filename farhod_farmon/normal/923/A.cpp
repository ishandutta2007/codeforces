#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int s[N];
int t[N];
vector < int > v[N];

void solve()
{
        for(int i = 2; i < N; i++){
                if(!v[i].empty()){
                        continue;
                }
                for(int j = i; j < N; j += i){
                        v[j].push_back(i);
                }
        }
        int ans = 1e9;
        int x;
        cin >> x;
        s[x] = 1; s[x + 1] = -1;
        for(int i = 0; i < 3; i++){
                ans = 1e9;
                for(int j = 1; j < N; j++){
                        s[j] += s[j - 1];
                        if(j >= 3 && s[j] >= 1){
                                ans = min(ans, j);
                        }
                        if(s[j] >= 1){
                                for(int p: v[j]){
                                        int last = (j / p - 1) * p;
                                        last = max(last, p);
                                        t[last + 1]++;
                                        t[j + 1]--;
                                }
                        }
                }
                for(int j = 0; j < N; j++){
                        s[j] = t[j];
                        t[j] = 0;
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