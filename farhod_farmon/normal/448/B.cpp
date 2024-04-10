#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s, t;
        cin >> s >> t;

        int p = 0;
        for(char c: s){
                if(p < t.size() && c == t[p]){
                        p += 1;
                }
        }
        if(p == t.size()){
                cout << "automaton\n";
                return 0;
        }

        vector < int > A(26, 0), B(26, 0);

        for(char c: s){
                A[c - 'a'] += 1;
        }
        for(char c: t){
                B[c - 'a'] += 1;
        }

        bool sol2 = true, sol3 = true;
        for(int i = 0; i < 26; i++){
                if(A[i] != B[i]){
                        sol2 = false;
                }
                if(A[i] < B[i]){
                        sol3 = false;
                }
        }
        if(sol2){
                cout << "array\n";
        } else if(sol3){
                cout << "both\n";
        } else{
                cout << "need tree\n";
        }
}