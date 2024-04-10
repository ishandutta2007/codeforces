
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a>b)swap(a,b);
        int l=c-d,r=c+d;
        if(l<=a&&b<=r){
            printf("0\n");
        }
        else if(a<=l&&r<=b){
            printf("%d\n",b-a-(r-l));
        }
        else if(r<=a||l>=b){
            printf("%d\n",b-a);
        }
        else if(r<=b){
            printf("%d\n",b-r);
        }
        else{
            printf("%d\n",l-a);
        }
    }
}