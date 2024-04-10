#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=200005;
unordered_map <int,int> f;
const int E=200;
char s[maxn];
int a[maxn],nxt[maxn],rt[maxn],n,st;
ll ans;
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    rt[n]=0; nxt[n]=n+1;
    for (int i=n;i;i--){
        if (s[i]=='1') nxt[i-1]=i,rt[i-1]=0;
        else nxt[i-1]=nxt[i],rt[i-1]=rt[i]+1;
    }
    for (int i=0;i<E;i++){
        f.clear(); f[0]=1;
        int sum=0;
        for (int j=1;j<=n;j++){
            if (s[j]=='1') sum-=i; else sum++;
            ans+=f[sum]; f[sum]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (s[i]=='1') st=i; else st=nxt[i];
        int ones=1;
        while (ones<=n/E){
            if (st==n+1) break;
            int len=st-i+1;
            ans+=max(0,(rt[st]+len)/ones-max(E,(len-1)/ones));
            st=nxt[st]; ones++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}