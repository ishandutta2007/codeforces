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
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    int Max=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=i){
            Max=i;
        }
    }
    double pro=1;
    for(int i = 0;i<m;i++){
        int r;
        double p;
        scanf("%d %lf",&r,&p);
        if(r>=Max){
            pro*=(1-p);
        }
    }
    if(Max==0){
        printf("1\n");
    }
    else{
        printf("%.12f\n",1-pro);
    }
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}