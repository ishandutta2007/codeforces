/**
    author: erray
    created: 02.03.2020 20:34
**/
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define all(v) v.begin(),v.end()
#define ln '\n'
#define MOD 1000000007
#define N 105
using namespace std;
int n, ans;
string s;
//vector <char> dep[N][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    cin >> n >> s;
    int ans = 0;
    bool b = 1;
    for(int i = 'z'; i >= 'b'; i--){
        for(int j = 0; j < s.size(); j++){
            if(s[j] == i){
                b = 1;
                int r = j + 1, l = j - 1;
                if(r < s.size()){
                    if(s[r] == i - 1){
                        s.erase(s.begin() + j);
                        j = -1;
                        b = 0;
                    }
                }
                if(l >= 0 && b){
                    if(s[l] == i - 1){
                        s.erase(s.begin() + j);
                        j = -1;
                    }
                }
            }
        }
    }
    //  cout << s << ln;
    cout << n - s.size() << ln;
}