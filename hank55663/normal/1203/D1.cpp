#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    char s[200005],t[200005];
    scanf("%s %s",s,t);
    int n=strlen(s),m=strlen(t);
    int l[200005],r[200005];
    l[0]=0;
    for(int i=0;i<m;i++){
        while(s[l[i]]!=t[i]){
            l[i]++;
        }
        l[i+1]=l[i]+1;
    }
    r[m-1]=n-1;
    for(int i = m-1;i>=0;i--){
        while(s[r[i]]!=t[i]){
            r[i]--;
        }
        if(i!=0)
        r[i-1]=r[i]-1;
    }
    int ans=max(r[0],n-l[m-1]-1);
    for(int i = 0;i<m-1;i++){
        //printf("%d %d\n",l[i],r[i]);
        ans=max(ans,r[i+1]-l[i]-1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */