#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

string s, t;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        vector < int > v;
        char c = 'b';
        for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] != c){
                        c = s[i];
                        v.push_back(1);
                }
                else{
                        v.push_back(0);
                }
        }
        reverse(v.begin(), v.end());
        for(int x: v){
                cout << x << " ";
        }
}