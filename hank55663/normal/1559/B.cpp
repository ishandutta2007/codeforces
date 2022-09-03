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
    int n;
    scanf("%d",&n);
    char c[105];
    scanf("%s",c);
    int ans=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i-1]=='?');
        else{
            if(c[i-1]==c[i])ans++;
            else if(c[i]=='?'){
                if(c[i-1]=='R')c[i]='B';
                else c[i]='R';
            }
        }
    }
    if(c[n-1]=='?'){
        for(int i = 0;i<n;i++)printf("%c","RB"[i&1]);
        printf("\n");
    }
    else{
        for(int i = n-2;i>=0;i--){
            if(c[i]=='?'){
                if(c[i+1]=='R')c[i]='B';
                else c[i]='R';
            }
        }
        printf("%s\n",c);
    }
   // printf("%d\n",ans);
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