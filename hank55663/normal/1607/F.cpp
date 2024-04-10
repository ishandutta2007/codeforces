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
const int mod=998244353;
char c[2005][2005];
int ans[2005][2005];
int loc[2005][2005];
int n,m;
vector<pair<short,short> > stk;
int val;
int go(int x,int y,int d){
    int st=0;
    int go=0;
    while(true){
        if(x<=0||y<=0||x>n||y>m){
            st=0;
            break;
        }
        if(ans[x][y]){
            st=ans[x][y];
            break;
        }
        if(loc[x][y]){
            st=0;
            go=1;
            break;
        }
        loc[x][y]=1;
        stk.pb(mp(x,y));
        if(c[x][y]=='R'){
            y++;//ans[x][y]=go(x,y+1,d+1)+1;
        }
        else if(c[x][y]=='L'){
            y--;//ans[x][y]=go(x,y-1,d+1)+1;
        }
        else if(c[x][y]=='U'){
            x--;//ans[x][y]=go(x-1,y,d+1)+1;
        }
        else if(c[x][y]=='D'){
            x++;//ans[x][y]=go(x+1,y,d+1)+1;
        }
        //printf("%d %d %c\n",x,y,c[x][y]);
        //getchar();
    }
   // printf("!\n");
    reverse(stk.begin(),stk.end());
    for(int i = 0;i<stk.size();i++){
        ans[stk[i].x][stk[i].y]=st+i+1;
    }
       reverse(stk.begin(),stk.end());
    if(go){
        val=ans[x][y];
    }
    return ans[x][y];
}
void solve(){
    //int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j = 1;j<=m;j++){
            ans[i][j]=0;
            loc[i][j]=0;
        }
    }
    int aa=0;
    int ansx=1,ansy=1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(ans[i][j]==0){
                val=0;
                stk.clear();
                go(i,j,1);
                int a=val;
 //               go2(i,j,1);
              //  printf("%d %d %d\n",i,j,val);
      
                while(val--){
                            assert(stk.size());
                    ans[stk.back().x][stk.back().y]=a;
                    stk.pop_back();
                }
            }
            if(ans[i][j]>aa){
                aa=ans[i][j];
                ansx=i;
                ansy=j;
            }
        }   
    }
    printf("%d %d %d\n",ansx,ansy,aa);
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