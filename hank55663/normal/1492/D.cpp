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
void solve(){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    if(b==1||a==0||k==0){
        if(k==0){
            printf("Yes\n");
            for(int j = 0;j<b;j++)
            printf("1");
            for(int j = 0;j<a;j++)printf("0");
            printf("\n");
            for(int j = 0;j<b;j++)
            printf("1");
            for(int j = 0;j<a;j++)printf("0");
            printf("\n");
        }
        else{
            printf("No\n");
        }
    }
    else if(k>=a+b-1){
        printf("No\n");
    }
    else{
        int ansa[200005];
        int ansb[200005];
        MEMS(ansa);
        MEMS(ansb);
        ansa[0]=1;
        ansb[0]=1;
        ansa[a+b-k-1]=1;
        ansb[a+b-k-1]=0;
        ansa[a+b-1]=0;
        ansb[a+b-1]=1;
        int tot=a+b;
        b-=2;
        a--;
        for(int i = 1;i<tot;i++){
            if(ansa[i]==-1){
                if(a)ansa[i]=ansb[i]=0,a--;
                else ansa[i]=ansb[i]=1;
            }
        }
        printf("Yes\n");
        for(int i = 0;i<tot;i++)printf("%d",ansa[i]);
        printf("\n");
        for(int i = 0;i<tot;i++)printf("%d",ansb[i]);
        printf("\n");
    }
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/