#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

bool can(int k)
{
        int s = 0;
        for(int i = 1; i <= n; i++){
                if(k < a[i]){
                        return false;
                }
                s -= a[i];
                s += k - a[i];
        }
        return s > 0;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int k = 1;
        while(!can(k)){
                k++;
        }
        cout << k << "\n";
}