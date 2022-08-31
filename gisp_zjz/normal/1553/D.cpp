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
char s[maxn],t[maxn];
int _,n,m;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s%s",s,t);
        n=strlen(s); m=strlen(t);
        if (n<m) {puts("NO");continue;}
        int p=0;
        if ((n-m)&1) p++;
        bool ok=1;
        for (int i=0;i<m;i++){
            while (p<n&&s[p]!=t[i]) p+=2;
            if (p>=n) {ok=0;break;} p++;
        }
        if (!ok) puts("NO"); else puts("YES");
    }
}