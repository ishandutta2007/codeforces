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
    char c[10];
    scanf("%s",c);
    int n=strlen(c);
    int ans=0;
    for(int i = 0;i<100000000;i+=25){
        char c2[10];
        sprintf(c2,"%d",i);
        int n2=strlen(c2);
        if(n!=n2)continue;
        int val=-1;
        int ok=1;
        for(int j = 0;c[j]!=0;j++){
            if(c[j]==c2[j])continue;
            if(c[j]=='_')continue;
            if(c[j]=='X'){
                if(val==-1)val=c2[j]-'0';
                else if(val!=c2[j]-'0')ok=0;
                continue;
            }
            ok=0;
        }
        ans+=ok;
    }
    printf("%d\n",ans);

}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
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