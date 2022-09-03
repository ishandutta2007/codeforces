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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int k;
    scanf("%d",&k);
    for(int i = 1;;i++){
        if(i%3!=0&&i%10!=3)k--;
        if(k==0){
            printf("%d\n",i);
            break;
        }
    }
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/