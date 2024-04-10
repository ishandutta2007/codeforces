#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int _,n;
char s[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",s+1);
        n=strlen(s+1);
        if (s[n]=='A'){puts("NO");continue;}
        int sum=0,flag=0;
        for (int i=1;i<=n;i++){
            if (s[i]=='A') sum++; else sum--;
            if (sum<0) flag=1;
        }
        if (!flag) puts("YES"); else puts("NO");
    }
}