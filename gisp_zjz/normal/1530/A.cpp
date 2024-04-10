#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _;
char s[10];
int main(){
    cin >> _;
    while (_--){
        cin >> s;
        int ans=0,n=strlen(s);
        for (int i=0;i<n;i++) ans=max(ans,s[i]-'0');
        cout << ans << endl;
    }
}