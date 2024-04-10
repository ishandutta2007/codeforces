#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                int last = 0;
                int A = 0, B = 0, cnt = 0;
                for(int it = 0, l = 0, r = n - 1; ; it ^= 1){
                        if(l > r){
                                break;
                        }
                        cnt += 1;
                        int cur = 0;
                        if(it == 0){
                                while(cur <= last && l <= r){
                                        cur += a[l++];
                                }
                                A += cur;
                        } else{
                                while(cur <= last && l <= r){
                                        cur += a[r--];
                                }
                                B += cur;
                        }
                        last = cur;
                }
                cout << cnt << " " << A << " " << B << "\n";
        }
}