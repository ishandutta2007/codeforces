#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int n;
int k;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int i = 1;
        while(k--){
                while(i <= n && a[i] == a[i - 1]){
                        i++;
                }
                if(i > n){
                        cout << 0 << "\n";
                }
                else{
                        cout << a[i] - a[i - 1] << "\n";
                        i++;
                }
        }
}