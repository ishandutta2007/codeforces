#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;
        n = s.size() - 1;
        for(int i = 0; i + 1 < s.size(); i++){
                if(s[i] > s[i + 1]){
                        n = i;
                        break;
                }
        }
        for(int i = 0; i < s.size(); i++){
                if(i == n){
                        continue;
                }
                cout << s[i];
        }
}