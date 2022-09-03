#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int C[15][15];
void build(){
    for(int i = 0;i<15;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
LL cal(int len,int *cnt){
    LL dp[15];
    MEM(dp);
    dp[0]=1;
    for(int i =0;i<16;i++){
        for(int j= 14;j>=0;j--){
            for(int k = 1;k<=cnt[i];k++){
                if(j+k<=len)
                    dp[j+k]+=dp[j]*C[len-j][k];
            }
        }
    }
  //  for(int i=0;i<16;i++)
    //    printf("%d ",cnt[i]);
   // printf("\n%d %lld\n",len,dp[len]);
    return dp[len];
}
int main(){
    build();
    int cnt[16];
    int k,t;
    scanf("%d %d",&k,&t);
    for(int i=0;i<16;i++)
        cnt[i]=t;
    for(int i = 1;i<16;i++){
        cnt[1]--;
        LL tot=cal(i-1,cnt)*15;
        if(tot>=k){
            cnt[1]++;
            int len=i;
           // printf("%d\n",i);
            string ans;
            for(int j = 1;j<=len;j++){
                for(int num = 0;num<16;num++){
                    if(j==1&&num==0){
                        continue;
                    }
                    if(cnt[num]==0)
                    continue;
                    cnt[num]--;
                    LL x=cal(len-j,cnt);
                    if(x>=k){
                        char c;
                        if(num<10){
                            c=num+'0';
                        }
                        else{
                            c='a'+num-10;
                        }
                        ans+=c;
                        break;
                    }
                    else{
                        k-=x;
                    }
                    cnt[num]++;
                }
            }
            cout<<ans<<endl;
            break;
        }
        else{
            k-=tot;
        }
        cnt[1]++;
    }
}