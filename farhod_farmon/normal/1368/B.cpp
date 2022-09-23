#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s = "codeforces";
        long long need;
        cin >> need;
        vector < int > a((int)s.size(), 1);
        long long cur = 1;
        int i = 0;
        while(cur < need){
                cur = cur / a[i] * (a[i] + 1);
                a[i] += 1;
                i = (i + 1) % (int)s.size();
        }
        for(int i = 0; i < s.size(); i++){
                while(a[i]--){
                        cout << s[i];
                }
        }
}