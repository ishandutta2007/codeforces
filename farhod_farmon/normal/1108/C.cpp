#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 130;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        vector < char > v, ans;
        v = {'B', 'R', 'G'};
        int res = 1e9;
        cin >> n >> s;
        sort(v.begin(), v.end());
        do{
                int cnt = 0;
                for(int i = 0; i < n; i++){
                        cnt += s[i] != v[i % 3];
                }
                if(cnt < res){
                        res = cnt;
                        ans = v;
                }
        }while(next_permutation(v.begin(), v.end()));
        cout << res << "\n";
        for(int i = 0; i < n; i++){
                cout << ans[i % 3];
        }
}