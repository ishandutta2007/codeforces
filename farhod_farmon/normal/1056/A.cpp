#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

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
                int k;
                cin >> k;
                for(int j = 1; j <= k; j++){
                        int  x;
                        cin >> x;
                        a[x]++;
                }
        }
        for(int i = 1; i < N; i++){
                if(a[i] == n){
                        cout << i << " ";
                }
        }
}