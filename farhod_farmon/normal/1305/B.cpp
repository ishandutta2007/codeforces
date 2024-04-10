#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400200;
const int Q = 400200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        string s;
        cin >> s;
        vector < int > A, B;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == '(') A.push_back(i + 1);
                else B.push_back(i + 1);
        }
        reverse(A.begin(), A.end());
        vector < int > v1, v2;
        while(!A.empty() && !B.empty() && A.back() < B.back()){
                v1.push_back(A.back());
                v2.push_back(B.back());
                A.pop_back();
                B.pop_back();
        }
        if(!v1.empty()){
                cout << 1 << "\n";
                cout << v1.size() * 2 << "\n";
                for(int x: v1)cout << x << " ";
                reverse(v2.begin(), v2.end());
                for(int x: v2)cout << x << " ";
        } else{
                cout << 0 << "\n";
        }
}