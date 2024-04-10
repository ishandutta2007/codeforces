#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=998244353;
const int N=2e5+50;
char str[N];
int num[N];
int n;
ll f[N][1<<6|5];
ll dfs(int i,int l1,int l2,int l3,int o1,int o2,int o3) {
    // cerr << o1 << " " << o2 << " " << o3 << endl;
    if(i==n+1) return !o1 && !o2 && !o3;
    int st=(l1)|(l2<<1)|(l3<<2)|(o1<<3)|(o2<<4)|(o3<<5);
    if(f[i][st]!=-1) return f[i][st];
    ll t=0;
    FOR(a,0,l1?num[i]:1) FOR(b,0,l2?num[i]:1) FOR(c,0,l3?num[i]:1) {
        int x1=a^b,x2=a^c,x3=b^c;
        if(!x1 && !x2 && !x3) {
            t=(t+dfs(i+1,l1 && a==num[i],l2 && b==num[i],l3 && c==num[i],o1,o2,o3))%Mod;
        } else if(!x1) {
            t=(t+dfs(i+1,l1 && a==num[i],l2 && b==num[i],l3 && c==num[i],0,o2,o3))%Mod;
        } else if(!x2) {
            t=(t+dfs(i+1,l1 && a==num[i],l2 && b==num[i],l3 && c==num[i],o1,0,o3))%Mod;
        } else {
            t=(t+dfs(i+1,l1 && a==num[i],l2 && b==num[i],l3 && c==num[i],o1,o2,0))%Mod;
        }
    }
    return f[i][st]=t;
}
int main() {
    memset(f,-1,sizeof(f));
    scanf("%s",str+1);
    n=strlen(str+1);
    FOR(i,1,n) num[i]=str[i]-'0';
    printf("%lld\n",dfs(1,1,1,1,1,1,1));
    return 0;
}