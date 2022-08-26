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
int n,m;
char s[maxn],t[maxn];
int main(){
    int _; cin >> _;
    while (_--){
        cin >> s >> t;
        n=strlen(s); m=strlen(t);
        bool ok=0;
        for (int i=0;i<n;i++)
        for (int j=i;j<n;j++){
            bool flag=1;
            int p=0;
            if (j-i+1>m) continue;
            for (int k=i;k<j;k++) flag&=(s[k]==t[p]),p++;
            for (int k=j;p<m;k--) flag&=(k>=0&&s[k]==t[p]),p++;
            if (flag) {ok=1;break;}
        }
        if (ok) puts("YES"); else puts("NO");
    }
}