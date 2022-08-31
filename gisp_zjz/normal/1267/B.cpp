#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[maxn],a[maxn];
int n,m,cnt[maxn];

int main(){
    cin >> s;
    n=strlen(s);
    for (int i=0;i<n;i++){
        if (i>0&&s[i]==s[i-1]) cnt[m]++;
        else m++,a[m]=s[i],cnt[m]=1;
    }
    if (m%2==0) {puts("0");return 0;}
    for (int i=1;i<=m/2;i++) if (a[i]!=a[m+1-i]||cnt[i]+cnt[m+1-i]<3) {puts("0");return 0;}
    if (cnt[(m+1)/2]>=2) printf("%d\n",cnt[(m+1)/2]+1);
    else puts("0");
    return 0;
}