#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[300005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    map<LL,int> m;
    LL ans=0;
    LL add = 0,flag=-1;
    m[0]=1;
    for(int i = 0;i<n;i++){
        add=-add;
        flag*=-1;
        add+=a[i];
        ans+=m[add*flag*-1];
       //printf("%lld %lld\n",add*flag*-1,ans);
        if(flag==-1){
             while(m.size()){
                auto it=*m.rbegin();
                if(-it.x+add<0){
                  //  printf("er %d\n",it.x);
                    m.erase(it.x);
                }
                else{
                    break;
                }
            }
        }
        else{
            while(m.size()){
                auto it=*m.begin();
                
                if(it.x+add<0){
                //     printf("er 1 %d\n",it.x);
                    m.erase(m.begin());
                }
                else{
                    break;
                }
            }
        }
        //printf("%lld %lld\n",(-add),flag);
        m[(-add)*flag]++;
    }
    printf("%lld\n",ans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/