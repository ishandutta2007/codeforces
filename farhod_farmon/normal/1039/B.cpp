#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

bool query(long long l, long long r)
{
        cout << l << " " << r << endl;
        string s;
        cin >> s;
        if(s[0] == 'B') exit(0);
        return s[0] == 'Y';
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        srand(time(NULL));
        long long n, k;
        cin >> n >> k;
        long long l = 1, r = n;
        while(l < r){
                while(r - l > 4 * k){
                        long long m = (l + r) / 2;
                        if(query(l, m)){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                        l = max(1ll, l - k);
                        r = min(n, r + k);
                }
                long long gg = (rand()) % (r - l + 1);
                if(query(l + gg, l + gg)){
                        return 0;
                }
                l = max(1ll, l - k);
                r = min(n, r + k);
        }
        query(l, r);
        return 0;
}