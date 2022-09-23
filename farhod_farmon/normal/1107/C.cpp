#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        long long res = 0;
        for(int i = 1; i <= n; ){
                vector < int > v;
                int j = i;
                while(j <= n && c[j] == c[i]){
                        v.push_back(a[j]);
                        j += 1;
                }
                i = j;
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                for(int j = 0; j < min((int)v.size(), k); j++){
                      res += v[j];
                }
        }
        cout << res << "\n";
}