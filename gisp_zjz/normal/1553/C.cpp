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
int _,n,f[15];
char s[15];
int work(){
    int cnt=0;
    for (int i=1;i<=10;i++){
        if (f[i]) ++cnt; else --cnt;
        if (abs(cnt)>10-i) return i;
    }
    return 10;
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",s+1);
        for (int i=1;i<=10;i++){
            if (s[i]!='?') f[i]=(s[i]-'0')^(i&1); else f[i]=0;
        }
        int ans=work();
        for (int i=1;i<=10;i++){
            if (s[i]!='?') f[i]=(s[i]-'0')^(i&1); else f[i]=1;
        }
        ans=min(ans,work());
        printf("%d\n",ans);
    }
    return 0;
}