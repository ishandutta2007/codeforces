#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i + 1 < n; i++){
                if(s[i] != s[i + 1]){
                        cout << "YES\n";
                        cout << s[i] << s[i + 1];
                        return 0;
                }
        }
        cout << "NO";
}