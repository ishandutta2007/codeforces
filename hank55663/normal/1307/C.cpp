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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int main(){
    char c[100005];
    scanf("%s",c);
    int cnt[26];
    MEM(cnt);
    for(int i = 0;c[i]!=0;i++){
        cnt[c[i]-'a']++;
    }
    LL ans=0;
    for(int i = 0;i<26;i++){
        ans=max(ans,(LL)cnt[i]);
    }
    for(int i = 0;i<26;i++){
        for(int j = 0;j<26;j++){
            MEM(cnt);
            LL sum=0;
            for(int k=0;c[k]!=0;k++){
                if(c[k]-'a'==j){
                    sum+=cnt[i];
                }
                cnt[c[k]-'a']++;
            }
            ans=max(ans,sum);
        }
    }
    printf("%lld\n",ans);
}