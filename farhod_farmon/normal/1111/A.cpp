#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

vector < char > v = {'a', 'e', 'i', 'o', 'u'};

int tp(char c)
{
        for(char x: v){
                if(x == c){
                        return 1;
                }
        }
        return 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s, t;
        cin >> s >> t;
        if(s.size() != t.size()){
                cout << "No" << "\n";
                return 0;
        }
        for(int i = 0; i < s.size(); i++){
                if(tp(s[i]) != tp(t[i])){
                        cout << "No" << "\n";
                        return 0;
                }
        }
        cout << "Yes" << "\n";
}