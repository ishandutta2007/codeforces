#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400200;

using namespace std;

int n;
int a[N];
int b[N];
int L[N];
int t[N][20];

int get(int l, int r)
{
        int g = L[r - l + 1];
        return max(t[l][g], t[r - (1 << g) + 1][g]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n + n + n; i++){
                if(i <= n){
                        cin >> a[i];
                } else{
                        a[i] = a[i - n];
                }
                t[i][0] = a[i];
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n + n + n; j++){
                        if(j + (1 << i) - 1 >= n + n + n){
                                continue;
                        }
                        t[j][i] = max(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
                }
        }
        for(int i = 1; i <= n + n + n; i++){
                int l = 0, r = i - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(a[i] * 2 < get(m + 1, i - 1)){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                b[i] = l;
        }
        for(int i = 1; i <= n + n + n; i++){
                t[i][0] = b[i];
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n + n + n; j++){
                        if(j + (1 << i) - 1 >= n + n + n){
                                continue;
                        }
                        t[j][i] = max(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
                }
        }
        for(int i = 1; i <= n; i++){
                int l = i, r = n + n + n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(get(i, m) >= i){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                if(l == n + n + n){
                        cout << -1 << " ";
                } else{
                        cout << l - i << " ";
                }
        }
}