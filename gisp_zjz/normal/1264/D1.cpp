#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=2005;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
int C[2005][2005],S[2005][2005],n,ans,os[maxn],ls[maxn],rs[maxn],p2[maxn];
char s[2005];

int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=0;i<=n;i++){
        C[i][0]=C[i][i]=S[i][0]=1;
        for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
        for (int j=1;j<=n;j++) S[i][j]=(S[i][j-1]+C[i][j])%M;
    }
    p2[0]=1; for (int i=1;i<=n;i++) p2[i]=p2[i-1]*2%M;
    for (int i=1;i<=n;i++) {
        ls[i]=ls[i-1]+(s[i]=='(');
        rs[i]=rs[i-1]+(s[i]==')');
        os[i]=os[i-1]+(s[i]=='?');
    }
    int L=ls[n],R=rs[n],U=os[n];
    for (int i=1;i<=n/2;i++) {
        add(ans,p2[U]);
        for (int j=0;j<i-L;j++) sub(ans,C[U][j]);
        for (int j=1;j<=n;j++){
            int res=0;
            if (s[j]=='('){
                int x=os[j],y=i-ls[j];
                if (x>=y) res=C[x][y];
            } else if (s[j]=='?'){
                int x=os[j-1],y=i-1-ls[j];
                if (x>=y) res=C[x][y];
            }
            if (res) {
                int x=U-os[j],y=R-rs[j];
                if (y<=i-1) sub(ans,1ll*res*S[x][i-1-y]%M);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}