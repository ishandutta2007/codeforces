#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2003;
char s[maxn],t[maxn];
const int M=1000000007;
int B=2000;
int _,n,f[maxn][maxn*2],g[maxn][maxn*2],ls[maxn],rs[maxn],lt[maxn],rt[maxn];
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        scanf("%s%s",s,t);
        for (int i=1;i<n;i+=2){
            if (s[i]!='?') s[i]='0'+'1'-s[i];
            if (t[i]!='?') t[i]='0'+'1'-t[i];
        }
        for (int i=0;i<n;i++){
            if (s[i]=='?') ls[i]=0,rs[i]=1;
            else ls[i]=rs[i]=s[i]-'0';
            if (t[i]=='?') lt[i]=0,rt[i]=1;
            else lt[i]=rt[i]=t[i]-'0';
        }
        for (int i=0;i<=n;i++)
            for (int j=-i;j<=i;j++)
                f[i][j+B]=g[i][j+B]=0;
        f[0][B]=1;
        for (int i=0;i<n;i++)
            for (int j=-i;j<=i;j++) if (f[i][j+B])
                for (int x=ls[i];x<=rs[i];x++)
                    for (int y=lt[i];y<=rt[i];y++){
                        int k=j+x-y;
                        add(f[i+1][k+B],f[i][j+B]);
                        add(g[i+1][k+B],g[i][j+B]);
                        add(g[i+1][k+B],1ll*abs(k)*f[i][j+B]%M);
                    }
        printf("%d\n",g[n][B]);
    }
    return 0;
}