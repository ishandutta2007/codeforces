#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+19;
int a[11],n,m;
bool f[11][1111];
char s[maxn];
int main(){
    for (n=1;n<=9;++n){
        for (int i=0;i<(1<<n);i++){
            for (int j=0;j<n;j++) a[j]=(bool)(i&(1<<j));
            bool w=0;
            for (int x=0;x<n;x++)
                for (int y=1;x+y*2<n;y++)
                    if (a[x]==a[x+y]&&a[x+y]==a[x+y*2]) w=1;
            f[n][i]=w;
        }
    }
    scanf("%s",s+1);
    m=strlen(s+1);
    long long ans=0;
    for (int i=1;i<=m;i++){
        int p=0;
        for (int j=1;i+j-1<=m&&j<=9;j++){
            p=p*2+(s[i+j-1]-'0');
            ans=ans+f[j][p];
        }
        ans=ans+max(0,(m-i+1)-9);
    }
    printf("%I64d\n",ans);
    return 0;
}