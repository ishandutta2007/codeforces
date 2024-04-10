#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 18;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                string s;
                cin >> s;
                vector < char > v;
                for(char c: s){
                        if(!v.empty() && c == 'B'){
                                v.pop_back();
                        } else{
                                v.push_back(c);
                        }
                }
                cout << v.size() << "\n";
        }
}