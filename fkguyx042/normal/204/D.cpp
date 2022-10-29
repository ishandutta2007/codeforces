#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define For(i,a,n)  for(int i=(a);i<=(n);i++)
#define Forn(i,a,n) for(int i=(a);i>=(n);i--)
#define REP(i,n)    for(int i=(1);i<=(n);i++)
using namespace std;
const int N=1000005;
const int mod=1000000007;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
    string in=a+".in",out=a+".out";
    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
#endif
}

int n,k;
char st[N];
int s0[N],s1[N],f[3][2][N];

inline int calc(char c, int *s, int i, int t) {
  if (i<k||st[i-k]==c||s[i]-s[i-k]) return 0;
  return f[t-1][i==k?0:2-t][i-k];
}
 
int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",st+1);
    f[0][0][0]=1;
    For(i,1,n){
        s0[i]=s0[i-1]+(st[i]=='W');
        s1[i]=s1[i-1]+(st[i]=='B');
        if (st[i]!='W') {
            f[0][0][i]=(0ll+f[0][1][i-1]+f[0][0][i-1]-calc('B',s0,i,1)+mod)%mod;
            f[1][0][i]=(0ll+f[1][0][i-1]+f[1][1][i-1]+calc('B',s0,i,1))% mod;
            f[2][0][i]=(0ll+f[2][0][i-1]+f[2][1][i-1])%mod;
        }
        if (st[i]!='B') {
            f[0][1][i]=(0ll+f[0][1][i-1]+f[0][0][i-1])%mod;
            f[1][1][i]=(0ll+f[1][0][i-1]+f[1][1][i-1]-calc('W',s1,i,2)+mod)%mod;
            f[2][1][i]=(0ll+f[2][0][i-1]+f[2][1][i-1]+calc('W',s1,i,2))%mod;
        }
    }
    printf("%d\n",(0ll+f[2][0][n]+f[2][1][n])%mod);
    return 0;
}