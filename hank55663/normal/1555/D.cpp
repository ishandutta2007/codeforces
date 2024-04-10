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
    int n,m;
    scanf("%d %d",&n,&m);
    char c[200005];
    scanf("%s",c+1);
    int pre[6][200005];
    char c2[10]="abc";
    int now=0;
    do{
       // printf("%d\n",now);
        pre[now][0]=0;
        for(int j = 1;j<=n;j++){
            pre[now][j]=pre[now][j-1];
            if(c[j]!=c2[j%3])pre[now][j]++;
        }
        now++;
    }while(next_permutation(c2,c2+3));
    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        int ans=1e9;
        for(int j = 0;j<6;j++)ans=min(ans,pre[j][r]-pre[j][l-1]);
        printf("%d\n",ans);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/