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
#define N 100005
#define MXN 2000005
int main(){
    int n;
    scanf("%d",&n);
    int a[505][505];
    for(int i=0;i<n;i++)
        for(int j =0;j<n;j++)
            scanf("%d",&a[i][j]);
    if(n==1){
        printf("1\n");
    }
    else{
        vector<LL> v1,v2;
        for(int i = 0;i<n;i++){
            LL sum1=0,sum2=0;
            int ok1=1,ok2=1;
            for(int j=0;j<n;j++){
                sum1+=a[i][j];
                sum2+=a[j][i];
                if(a[i][j]==0){
                    ok1=0;
                }
                if(a[j][i]==0){
                    ok2=0;
                }
            }
            if(ok1)v1.pb(sum1);
            else v2.pb(sum1);
            if(ok2)v1.pb(sum2);
            else v2.pb(sum2);
        }
        LL sum1=0;
        int ok=1;
        for(int i = 0;i<n;i++){
            sum1+=a[i][i];
            if(a[i][i]==0)ok=0;
        }
        if(ok)v1.pb(sum1);
        else v2.pb(sum1);
        sum1=0;
        ok=1;
        for(int i = 0;i<n;i++){
            sum1+=a[n-i-1][i];
            if(a[n-i-1][i]==0)ok=0;
        }
        if(ok)v1.pb(sum1);
        else v2.pb(sum1);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1[0]==v1.back()&&v2[0]==v2.back()&&v2[0]<v1[0]){
            printf("%lld\n",v1[0]-v2[0]);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}