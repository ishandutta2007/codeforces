#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=500050;
int dp[255][255][255];
int n,q,A,B,C,nxt[maxn][26],last[26],ID;
char s[maxn],a[255],b[255],c[255],o[1],t[1];
void Min(int &x,int y){
    if (y<x) x=y;
}

int main(){
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for (int i=0;i<26;i++) nxt[n+1][i]=last[i]=n+1;
    for (int i=n;i>=0;i--){
        for (int j=0;j<26;j++) nxt[i][j]=last[j];
        last[s[i]-'a']=i;
    }
    for (int i=0;i<255;i++)
        for (int j=0;j<255;j++)
            for (int k=0;k<255;k++)
                dp[i][j][k]=n+1;
    dp[0][0][0]=0;
    for (int i=1;i<=q;i++){
        scanf("%s",o);
        if (o[0]=='-'){
            scanf("%d",&ID);
            if (ID==1) A--;
            else if (ID==2) B--;
            else if (ID==3) C--;
        } else {
            scanf("%d%s",&ID,t);
            if (ID==1){
                A++; a[A]=t[0];
                int r=t[0]-'a';
                for (int j=0;j<=B;j++)
                for (int k=0;k<=C;k++){
                    dp[A][j][k]=nxt[dp[A-1][j][k]][r];
                    if (j>0) Min(dp[A][j][k],nxt[dp[A][j-1][k]][b[j]-'a']);
                    if (k>0) Min(dp[A][j][k],nxt[dp[A][j][k-1]][c[k]-'a']);
                }
            } else if (ID==2){
                B++; b[B]=t[0];
                int r=t[0]-'a';
                for (int j=0;j<=A;j++)
                for (int k=0;k<=C;k++){
                    dp[j][B][k]=nxt[dp[j][B-1][k]][r];
                    if (j>0) Min(dp[j][B][k],nxt[dp[j-1][B][k]][a[j]-'a']);
                    if (k>0) Min(dp[j][B][k],nxt[dp[j][B][k-1]][c[k]-'a']);
                }
            } else if (ID==3){
                C++; c[C]=t[0];
                int r=t[0]-'a';
                for (int j=0;j<=A;j++)
                for (int k=0;k<=B;k++){
                    dp[j][k][C]=nxt[dp[j][k][C-1]][r];
                    if (j>0) Min(dp[j][k][C],nxt[dp[j-1][k][C]][a[j]-'a']);
                    if (k>0) Min(dp[j][k][C],nxt[dp[j][k-1][C]][b[k]-'a']);
                }
            }
        }
        if (dp[A][B][C]<=n) puts("YES"); else puts("NO");
    }
    return 0;
}