#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
LL pow3[200005];
int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    pow3[0]=1;
    for(int i = 1;i<200005;i++)pow3[i]=pow3[i-1]*3%mod;
  //  LL tot=0;
    int qcnt=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?')qcnt++;
    }
    LL tot=0;
    LL cnt[4][3];
    memset(cnt,0,sizeof(cnt));
    for(int i = 0;c[i]!=0;i++){
        for(int j = 3;j>=0;j--){
            if(c[i]!='?'){
                if(c[i]=='a'){if(j==0)cnt[j][0]++,cnt[j][0]%=mod;}
                else cnt[j][c[i]-'a']+=cnt[j][c[i]-'a'-1],cnt[j][c[i]-'a']%=mod;
            }
            else{
                if(j!=3){
                    if(j==0)
                    cnt[j+1][0]++;
                    cnt[j+1][1]+=cnt[j][0];
                    cnt[j+1][2]+=cnt[j][1];
                    cnt[j+1][0]%=mod;
                    cnt[j+1][1]%=mod;
                    cnt[j+1][2]%=mod;
                }
            }
            
        }
        /*for(int j = 3;j>=0;j--){
printf("%d %d %d %d %d\n",i,j,cnt[j][0],cnt[j][1],cnt[j][2]);
        }
        printf("\n");*/
    }
    for(int i=0;i<4&&i<=qcnt;i++){
        tot+=pow3[qcnt-i]*(cnt[i][2])%mod;//+pow3[cnt%mod;
       // printf("%lld\n",tot);
        tot=(tot%mod+mod)%mod;
    }
    printf("%lld\n",tot);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}