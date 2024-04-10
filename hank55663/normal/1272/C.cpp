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
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[200005];
    scanf("%s",c);
    int ok[26];
    MEM(ok);
    for(int i = 0;i<k;i++){
        char cc;
        scanf(" %c",&cc);
        ok[cc-'a']=1;
    }
    LL cnt=0;
    LL ans=0;
    for(int i = 0;c[i]!=0;i++){
        if(ok[c[i]-'a'])cnt++;
        else{
            ans+=cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    ans+=cnt*(cnt+1)/2;
    printf("%lld\n",ans);
}