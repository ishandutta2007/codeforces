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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int main(){
    char c[100005];
    scanf("%s",c);
    int len=strlen(c);
    if(len&1){
        printf("-1\n");
        return 0;
    }
    int l=0,r=0,u=0,d=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='L')l++;
        if(c[i]=='R')r++;
        if(c[i]=='U')u++;
        if(c[i]=='D')d++;
    }
    printf("%d\n",(abs(l-r)+abs(u-d))/2);
}