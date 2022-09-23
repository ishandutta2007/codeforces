#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x]++;
        }
        int ans = 1;
        for(int i = 2; i < N; i++){
                int cnt = 0;
                for(int j = i; j < N; j += i){
                        cnt += a[j];
                }
                ans = max(ans, cnt);
        }
        cout << ans << "\n";
}