#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50005;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                long long tl, tr;
                cin >> n >> tl >> tr;

                vector < int > cur;
                long long l = 0;
                for(long long i = 1; i <= n; i++){
                        l += 1;
                        long long r = l + 2 * (n - i) - 1;
                        if(i == n){
                                r += 1;
                        }
                        if(max(l, tl) > min(r, tr)){
                                l = r;
                                continue;
                        }

                        cur.clear();
                        for(int j = i + 1; j <= n; j++){
                                cur.push_back(i);
                                cur.push_back(j);
                        }
                        if(i == n){
                                cur.push_back(1);
                        }

                        int x = max(l, tl) - l;
                        int y = min(r, tr) - l;

                        while(x <= y){
                                cout << cur[x++] << " ";
                        }
                        l = r;
                }
                cout << "\n";
        }
}