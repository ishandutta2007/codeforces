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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[200005];
        scanf("%s",c+1);
        int l=1;
        int cnt[3];
        MEM(cnt);
        int ans=1e9;
        for(int i = 1;c[i]!=0;i++){
            cnt[c[i]-'1']++;
          //  printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);
            while(cnt[0]&&cnt[1]&&cnt[2]){
                ans=min(ans,i-l+1);
                cnt[c[l]-'1']--;
                l++;
            }
        }
        if(ans==1e9)ans=0;
        printf("%d\n",ans);
    }
}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/