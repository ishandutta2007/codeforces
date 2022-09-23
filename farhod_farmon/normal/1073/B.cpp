#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
int a[N];
bool used[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1, j = 1; i <= n; i++){
                int x;
                cin >> x;
                int cnt = 0;
                if(used[x]){
                        cout << 0 << " ";
                        continue;
                }
                while(a[j + cnt] != x){
                        used[a[j + cnt]] = true;
                        cnt++;
                }
                cout << cnt + 1 << " ";
                used[x] = true;
                j += cnt + 1;
        }
}