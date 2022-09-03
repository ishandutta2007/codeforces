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
#define MXN 200005
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[5005];
    scanf("%s",c);
    int a=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]==c[a])a++;
        else if(c[i]>c[a]){
            //printf("%d\n",i);
            for(int j = 0;j<k;j++){
                printf("%c",c[(j)%(i-a)]);
               
            }
             printf("\n");
                return;
        }
        else{
            a=0;
        }
    }
    for(int i = 0;i<k;i++){
        printf("%c",c[i%(n-a)]);
    }
    printf("\n");
}
int main(){
    int t=1;//00;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/