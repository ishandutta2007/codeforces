#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=1000000007;
int _,n;
string s,t,ans;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> s;
        int tot=0; t="";
        for (int i=0;i<n;i++) if (s[i]=='b') ++tot; else t+=s[i];
        ans="";
        for (int i=0;i<tot;i++) ans+="b"; ans+=t;
        cout << ans << endl;
    }
    return 0;
}