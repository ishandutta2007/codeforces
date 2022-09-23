#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        set < int > s;

        while(s.find(n) == s.end()){
                s.insert(n);
                n += 1;
                while(n % 10 == 0){
                        n /= 10;
                }
        }

        cout << s.size() << "\n";
}