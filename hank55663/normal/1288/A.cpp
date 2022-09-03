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
#define cpdd const pdd
#define rank Rank
#define KK 500
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        int ans=d;
        for(int i = 1;i<1000000;i++)
        {
            ans=min(ans,i+(d+i)/(i+1));
        }
        if(ans<=n)
        printf("YES\n");
        else 
        printf("NO\n");
    }
}