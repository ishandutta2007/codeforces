#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;

        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
                cnt += s[i] == 'a';
        }

        vector < int > v;
        for(int i = s.size(); i >= 0; i--){
                if(s[i] == 'a'){
                        break;
                }
                if(s.size() - i == i - cnt){
                        v.push_back(i);
                }
        }
        if(v.empty()){
                cout << ":(" << "\n";
                return 0;
        }

        string a = "", b = "";

        assert((int)v.size() == 1);

        for(int i = 0; i < v[0]; i++){
                a += s[i];
        }
        for(int i = 0; i < a.size(); i++){
                if(a[i] != 'a'){
                        b += a[i];
                }
        }
        b = a + b;
        if(b == s){
                cout << a << "\n";
        } else{
                cout << ":(" << "\n";
        }
}