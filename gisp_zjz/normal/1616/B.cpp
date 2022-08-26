#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _;
string s,t;
int main(){
    cin >> _;
    while (_--){
        int n; cin >> n >> s;
        if (n==1||s[0]<=s[1]) cout << s[0] << s[0] << endl;
        else {
            t=""; t+=s[0];
            for (int i=1;i<n;i++){
                if (s[i]<=s[i-1]) t+=s[i]; 
                else break;
            }
            cout << t;
            reverse(t.begin(),t.end());
            cout << t << endl;
        }
    }
    return 0;
}