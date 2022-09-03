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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    char a[100005],b[100005];
    scanf("%s %s",a,b);
    int cnt=0,cnt2=0;
    for(int i = 0;i<n;i++){
        if(a[i]=='1')cnt++;
        if(b[i]=='1')cnt2++;
    }
    if(cnt==0&&cnt2==0){
        printf("0\n");
    }
    else if(cnt==0||cnt2==0){
        printf("-1\n");
    }
    else if(cnt==cnt2&&cnt!=n-cnt2+1){
        int ans=0;
        for(int i = 0;a[i]!=0;i++){
            if(a[i]!=b[i]){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    else if(cnt==n-cnt2+1&&cnt!=cnt2){
        int add=1;
        int ans=0;
        for(int i = 0;a[i]!=0;i++){
            if(a[i]==b[i])ans++;
            if(a[i]=='1'&&b[i]=='1')add=0;
        }
        printf("%d\n",ans+add);
    }
    else if(cnt==cnt2&&cnt==n-cnt2+1){
        int x=0,y=0,add=1;
        for(int i = 0;a[i]!=0;i++){
            if(a[i]!=b[i])x++;
            else y++;
            if(a[i]=='1'&&b[i]=='1')add=0;
        }
        printf("%d\n",min(x,y+add));
    }
    else{
        printf("-1\n");
    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/