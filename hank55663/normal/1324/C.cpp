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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[200005];
        scanf("%s",c+1);
        int last=0,Max=1;
        int n=strlen(c+1)+1;
        for(int i = 1;c[i]!=0;i++){
            if(c[i]=='R'){
                Max=max(Max,i-last);
                last=i;
            }
        }
        Max=max(Max,n-last);
        printf("%d\n",Max);
    }
}
/*
4+3+3+4+3+2+2+1
*/