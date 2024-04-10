#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
int n;
char s[maxn],t[maxn];
int main(){
    int _; cin >> _;
    while (_--){
        cin >> n >> s;
        for (int i=0;i<n;i++) t[i]=s[i];
        sort(s,s+n);
        int ans=0;
        for (int i=0;i<n;i++) ans+=s[i]!=t[i];
        cout << ans << endl;
    }
}