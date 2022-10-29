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
typedef long long LL;
typedef double db;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
    string in=a+".in",out=a+".out";
    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
#endif
}

char s[100005];
int A,L,R;
int n,stk[100005],a[100005];

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    For(i,1,n) a[i]=a[i-1]+(s[i]=='[');
    For(i,1,n){
        if(s[i]=='(' || s[i]=='[') stk[++*stk]=i;else{
            if(!stk[0] || (s[stk[stk[0]]]!='[' && s[i]==']') || (s[stk[stk[0]]]!='(' && s[i]==')')){
                stk[stk[0]=1]=i;
            }else{
                --stk[0];
                int vl=stk[stk[0]]+1,vr=i,sum=a[vr]-a[vl-1];
                if(sum>A){
                    A=sum;
                    L=vl;R=vr;
                }
            }
        }
    }
    printf("%d\n",A);
    if(A)For(i,L,R) printf("%c",s[i]);puts("");
    return 0;
}