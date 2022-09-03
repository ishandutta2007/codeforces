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
const int mod=998244353;
vector<int> v[200005];
int cnt[32768];
void solve(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    for(int i = 0;i<n;i++){
        char c[65];
        scanf("%s",c);
        for(int j = 0;j<m;j++){
            if(c[j]=='1')v[i].pb(j);
        }
    }
    string ans;
    int Max=0;
    for(int j = 0;j<m;j++)ans+="0";
    srand(time(NULL));
    for(int t=0;t<60;t++){
        int x=(rand()*(1ll<<20)+rand())%n;
        int ok[60];
        int r[15];
        fill(ok,ok+60,-1);
        fill(cnt,cnt+32768,0);
        for(int j = 0;j<v[x].size();j++){
            ok[v[x][j]]=j;
            r[j]=v[x][j];
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(auto &it:v[j]){
                if(ok[it]!=-1)sum+=(1<<ok[it]);
            }
            cnt[sum]++;
          //  if(x==4)printf("%d\n",sum);
        }
        for(int j = 0;j<15;j++){
            for(int k = 0;k<32768;k++){
                if(k&(1<<j)){
                    cnt[k-(1<<j)]+=cnt[k];
                }
            }
        }
        int Maxa=0;
        for(int j = 0;j<32768;j++){
            if(cnt[j]>=(n+1)/2){
                if(__builtin_popcount(j)>__builtin_popcount(Maxa)){
                    Maxa=j;
                 //   if(x==4&&j==3){
                   //     printf("%d\n",cnt[j]);
                  //  }
                }
            }
        }
        if(__builtin_popcount(Maxa)>Max){
            Max=__builtin_popcount(Maxa);
            ans="";
           // printf("%d %d\n",x,Maxa);
            for(int j = 0;j<m;j++)ans+="0";
            for(int j = 0;j<15;j++){
                if(Maxa&(1<<j)){
                    ans[r[j]]='1';
                }
            }
        }
    }
    printf("%s\n",ans.c_str());
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/