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
#define MXN 200005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int p[400005];
        for(int i = 0;i<n;i++)
        scanf("%d",&p[i]);
        int g=0,s=0,b=0;
        int ss=-1,bb=-1;
        
        for(int i = 0;i<n;i++){
            if(p[i]==p[n/2])
            break;
            if(p[i]==p[0])g++;
            else if(p[i]==ss)s++;
            else{
                if(s<=g){
                    ss=p[i];
                    s++;
                }
                else{
                    b++;
                }
            }
            if(p[i]!=p[0]&&ss==-1)ss=p[i];
        }
        if(g>=s||g>=b){
            printf("0 0 0\n");
        }
        else{
            printf("%d %d %d\n",g,s,b);
        }
    }
}