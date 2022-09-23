#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> s;
        char best = 'z';
        for(char c: s){
                if(best < c){
                        cout << "Ann" << "\n";
                } else{
                        cout << "Mike" << "\n";
                        best = c;
                }
        }
}