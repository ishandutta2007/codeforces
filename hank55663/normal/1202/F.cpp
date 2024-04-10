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
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==0||b==0){
        printf("%d\n",max(a,b));
    }
    else{
        int ans=0;
        for(int i = 2;i<=a+b;){
            int need=(a+b)/i;
            int aa=a/need;
            int bb=b/need;
            int aaa=(a+need)/(need+1);
            int bbb=(b+need)/(need+1);
            int r=min(aa+bb,(a+b)/need);
            int l=max(aaa+bbb,i);
            if(aaa>aa||bbb>bb);
            else
            ans+=max(r-l+1,0);
           // printf("%d %d %d\n",i,r,l);
            i=(a+b)/need+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/* 
1 3 6 10 15
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */