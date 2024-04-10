#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MAXK 2500
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    int w[105];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    if(sum==x){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        do{
            int sum=0;
            for(int i = 0;i<n;i++){
                sum+=w[i];
                if(sum==x){
                    sum-=w[i];
                    swap(w[i],w[i+1]);
                    sum+=w[i];
                }
            }
            if(sum!=x){
                for(int i = 0;i<n;i++)printf("%d ",w[i]);
                printf("\n");
                break;
            }
            random_shuffle(w,w+n)
        ;}while(true);
    }
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36

x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/