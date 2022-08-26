#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=998244353;
int n,m,f[maxn],nf[maxn],inv[maxn],tot,q,ans,p2[maxn],nx,ny,cur,p[maxn];
char s[maxn];
int C(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void init(){
    f[0]=nf[0]=1; inv[1]=1; p2[0]=1; p[0]=1;
    for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    for (int i=1;i<maxn;i++) p2[i]=1ll*p2[i-1]*inv[2]%M,p[i]=1ll*p[i-1]*2%M;
}
int ask(int x,int y){
    if (x<0||y<0) return 0;
    while (ny>y) add(cur,M-C(nx,ny)),ny--;
    while (ny<y) ny++,add(cur,C(nx,ny));
    while (nx>x) nx--,cur=1ll*(cur+C(nx,ny))*inv[2]%M;
    while (nx<x) cur=(2ll*cur+M-C(nx,ny))%M,nx++;
    return cur;
}
int solve(int tot,int q){
    if (q==1){
        ans=0;
        for (int i=0;i<=q;i++){
            int sum=(tot-q)/2+i;
            if (sum%2) continue;
            add(ans,1ll*C(q,i)*abs(sum)%M);
        }
        ans=1ll*ans*p2[q]%M;
        return ans;
    } else {
        ans=0;
        int rv=(q-tot)/2;
        add(ans,1ll*p[q-2]*tot%M);
        int h=rv; if ((rv+h)%2) h--;
        if (h>=0){
            add(ans,2ll*ask(q-1,h)*rv%M);
            add(ans,M-2ll*ask(q-2,h-1)*q%M);
        }
        ans=1ll*ans*p2[q]%M;
        return (ans%M+M)%M;
    }
}
int main(){
    init(); nx=0; ny=0; cur=1;
    scanf("%d%d",&n,&m); q=0;
    scanf("%s",s);
    for (int i=1;i<n;i+=2) {
        if (s[i]=='w') s[i]='b';
        else if (s[i]=='b') s[i]='w';
    }
    for (int i=0;i<n;i++){
        if (s[i]=='w') ++tot; else if (s[i]=='b') --tot; else q++;
    }

    printf("%d\n",solve(tot,q));
    while (m--){
        int id; char t[3];
        scanf("%d%s",&id,t);
        id--;
        if (id%2==1){
            if (t[0]=='w') t[0]='b';
            else if (t[0]=='b') t[0]='w';
        }
        if (s[id]=='w') --tot; else if (s[id]=='b') ++tot; else q--;
        s[id]=t[0];
        if (s[id]=='w') ++tot; else if (s[id]=='b') --tot; else q++;
        printf("%d\n",solve(tot,q));
    }
    return 0;
}