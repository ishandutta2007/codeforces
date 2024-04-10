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
    char a[55],b[55];
    scanf("%s %s",a,b);
    int tot=strlen(a)+strlen(b);
    int ans=tot;
    for(int i = 0;a[i]!=0;i++){
        for(int j = 0;b[j]!=0;j++){
            for(int k = 0;a[i+k]!=0&&b[j+k]!=0;k++){
                if(a[i+k]==b[j+k]){
                    ans=min(ans,tot-2*(k+1));
                }
                else{
                    break;
                }
               // printf("%d %d %d\n",i,j,k);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/