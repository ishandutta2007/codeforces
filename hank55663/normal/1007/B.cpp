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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
vector<int> v[100005];
bool ok(int x,int y,int z){
    int a[3]={x,y,z};
    do{
        if((a[0]&1)&&(a[1]&2)&&(a[2]&4))return true;
    }while(next_permutation(a,a+3));
    return false;
}
int main(){
    for(int i = 1;i<100005;i++){
        for(int j=i;j<100005;j+=i){
            v[j].pb(i);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a[3];
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        int cnt[8];
        MEM(cnt);
        for(int i=0;i<3;i++){
            for(auto it:v[a[i]]){
                int val=0;
                if(a[0]%it==0)val++;
                if(a[1]%it==0)val+=2;
                if(a[2]%it==0)val+=4;
                cnt[val]++;
            }
        }
        for(int i = 1;i<8;i++){
            cnt[i]/=__builtin_popcount(i);
          //  printf("%d ",cnt[i]);
        }
      //  printf("\n");
        LL ans=0;
        for(int i = 1;i<8;i++){
            for(int j=i+1;j<8;j++){
                for(int k=j+1;k<8;k++){
                    if(ok(i,j,k)){
                        ans+=cnt[i]*cnt[j]*cnt[k];
                    }
                }
            }
        }
      //  printf("%d\n",ans);
        for(int i  =1;i<8;i++){
            for(int j=i+1;j<8;j++){
                if(ok(i,i,j)){
              //      printf("%d %d1\n",i,j);
                    ans+=(cnt[i]*(cnt[i]-1)/2+cnt[i])*cnt[j];
                }
                if(ok(i,j,j)){
                   // printf("%d %d2\n",i,j);
                    ans+=(cnt[j]*(cnt[j]-1)/2+cnt[j])*cnt[i];
                }
            }
        }
       // printf("%d\n",ans);
        ans+=(cnt[7]+cnt[7]*(cnt[7]-1)+cnt[7]*(cnt[7]-1)*(cnt[7]-2)/6);
        printf("%lld\n",ans);
    }
}