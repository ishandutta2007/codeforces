#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                int l = -1, r = -1, cnt = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        a[i] -= 1;
                        if(i != a[i]){
                                cnt += 1;
                                if(l == -1){
                                        l = i;
                                }
                                r = i;
                        }
                }
                if(l == -1){
                        cout << 0 << "\n";
                } else if(cnt == r - l + 1){
                        cout << 1 << "\n";
                } else{
                        cout << 2 << "\n";
                }
        }
}