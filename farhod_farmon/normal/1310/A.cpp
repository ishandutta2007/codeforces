#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
pair < int, int > a[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i].se;
        }
        long long res = 0, sum = 0, cur = 0;
        multiset < int > d;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                cur += 1;
                if(d.empty()){
                        cur = a[i].fi;
                }
                int j = i;
                while(a[j].fi == cur){
                        d.insert(a[j].se);
                        sum += a[j].se;
                        j += 1;
                }
                int mx = *(--d.end());
                sum -= mx;
                d.erase(d.find(mx));
                res += sum;
                i = j - 1;
        }
        while(d.size() > 0){
                int mx = *(--d.end());
                sum -= mx;
                d.erase(d.find(mx));
                res += sum;
        }
        cout << res << "\n";
}