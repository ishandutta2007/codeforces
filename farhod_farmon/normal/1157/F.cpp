#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

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
                a[x] += 1;
        }

        int res = 0, l, r;
        for(int i = 1; i < N; i++){
                if(a[i] == 0){
                        continue;
                }
                int cnt = a[i];
                int j = i + 1;
                while(a[j] > 1){
                        cnt += a[j];
                        j++;
                }
                cnt += a[j];
                if(cnt > res){
                        res = cnt;
                        l = i;
                        r = j;
                }
                i = j - 1;
        }
        if(!a[r]){
                r--;
        }
        cout << res << "\n";
        for(int i = l; i <= r; i++){
                cout << i << " ";
                a[i] -= 1;
        }
        for(int i = r; i >= l; i--){
                if(!a[i]){
                        continue;
                }
                while(a[i]--){
                        cout << i << " ";
                }
        }
}