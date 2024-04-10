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
        int n;
        scanf("%d",&n);
        LL sum=0,Min=0,Mini=0;
        LL ans=0;
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            sum+=x;
            if(Min>=sum){
                Min=sum;
                Mini=i+1;
            }
            if(i!=n-1||Mini!=0)
            ans=max(ans,sum-Min);
        }
        if(ans>=sum){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}