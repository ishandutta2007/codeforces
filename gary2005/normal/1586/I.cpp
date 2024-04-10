/**
 *    author:  gary
 *    created: 01.08.2022 22:07:45
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e3+20;
int n;
char c[MAXN][MAXN];
bool col[MAXN][MAXN];
bool can[MAXN][MAXN][2];
int id[MAXN][MAXN];
string S="SG";
int cnt,fa[MAXN*5],cancan[MAXN*5][2];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int x,int y){
    fa[root(x)]=root(y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) rb(j,1,n) cin>>c[i][j],col[i][j]=(i+j)&1;
    if(n&1){
        cout<<"NONE\n";
        return 0;
    }
    rep(i,MAXN) rep(j,MAXN) rep(k,2) can[i][j][k]=1;
    rb(i,1,n) rb(j,1,n) if(c[i][j]!='.'){
        bool x=(c[i][j]=='G');
        if(col[i][j]==1){
            int y=min(i-1,j-1);
            can[i-y][j-y][x^1^(y&1)]=0;
            y=min(n-i,n-j);
            can[i+y][j+y][x^1^(y&1)]=0;
        }
        else{
            int y=min(i-1,n-j);
            can[i-y][j+y][x^1^(y&1)]=0;
            y=min(n-i,j-1);
            can[i+y][j-y][x^1^(y&1)]=0;
        }
    }
    rb(i,1,n){
        rb(j,1,n) if(i==1||j==1||i==n||j==n) id[i][j]=++cnt;
    }
    rb(i,1,cnt) fa[i]=i,cancan[i][0]=cancan[i][1]=1;
    rb(i,1,n){
        merge(id[1][i],id[1][i+1]);
        merge(id[n][i],id[n][i+1]);
        merge(id[i][1],id[i+1][1]);
        merge(id[i][n],id[i+1][n]);
        i++;
    }
    rb(i,1,n){
        rb(j,1,n) if(i==1||j==1||i==n||j==n){
            if(col[i][j]==0){
                int y=min(i-1,n-j);
                merge(id[i][j],id[i-y][j+y]);
            }
            else{
                int y=min(i-1,j-1);
                merge(id[i][j],id[i-y][j-y]);
            }
        }
    }
    rb(i,1,n){
        rb(j,1,n) if(i==1||j==1||i==n||j==n){
            // if(root(id[i][j])==6){
            //     cout<<i<<" "<<j<<' '<<can[i][j][0]<<" "<<can[i][j][1]<<endl;
            // }
            cancan[root(id[i][j])][0]&=can[i][j][0];
            cancan[root(id[i][j])][1]&=can[i][j][1];
        }
    }
    int tot=1;
    rb(i,1,cnt){
        if(root(i)==i)
        {
            if(cancan[i][0]&&cancan[i][1]){
                tot=2;
            }
            if(!cancan[i][0]&&!cancan[i][1]){
                tot=0;
                break;
            }
        }
    }
    if(!tot){
        cout<<"NONE\n";
    }
    else if(tot>1){
        cout<<"MULTIPLE\n";
    }
    else {
        cout<<"UNIQUE\n";
        rb(i,1,n) rb(j,1,n) if(min(i,j)==1||max(i,j)==n){
            int now=cancan[root(id[i][j])][1];
            int x=i;
            int y=j;
            if(col[x][y]==0){
                while (x<=n&&y>=1){
                    c[x][y]=S[now];
                    now^=1;
                    x++;
                    y--;
                }
            }
            else{
                while (x<=n&&y<=n){
                    c[x][y]=S[now];
                    now^=1;
                    x++;
                    y++;
                }
            }
        }
        rb(i,1,n){
            rb(j,1,n) cout<<c[i][j];
            cout<<endl;
        }
    }
    return 0;
}