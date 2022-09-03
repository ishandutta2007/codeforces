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
int a[300005][8];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int Max=1e9+1,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int val[300];
        MEM(val);
        for(int i = 0;i<n;i++){
            int x=0;
            for(int j = 0;j<m;j++){
                if(a[i][j]>=mid)
                    x+=(1<<j);
            }
            val[x]++;
        }  
        int ok=0;
        for(int i = 0;i<(1<<m);i++){
            for(int j=0;j<(1<<m);j++){
                if(val[i]&&val[j]&&((i|j)==(1<<m)-1)){
                    ok=1;
                }
            }
        }
        if(ok){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    int val[300];
    MEM(val);
    for(int i = 0;i<n;i++){
        int x=0;
        for(int j = 0;j<m;j++){
            if(a[i][j]>=Min)
                x+=(1<<j);
        }
        val[x]=i+1;
    }
    for(int i = 0;i<(1<<m);i++){
        for(int j=0;j<(1<<m);j++){
            if(val[i]&&val[j]&&((i|j)==(1<<m)-1)){
                printf("%d %d\n",val[i],val[j]);
                return 0;
            }
        }
    }
}
//a+a+1=10a+1
//3a+2=10a+2