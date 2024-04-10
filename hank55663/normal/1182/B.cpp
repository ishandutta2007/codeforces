#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    char c[505][505];
    MEM(c);
    for(int i = 1;i<=h;i++)
        scanf("%s",c[i]+1);
    int tot=0;
    vector<pii> v;
    for(int i = 1;i<=h;i++){
        for(int  j=1;j<=w;j++){
            if(c[i][j]=='*'&&c[i+1][j]=='*'&&c[i-1][j]=='*'&&c[i][j+1]=='*'&&c[i][j-1]=='*'){
                v.pb(mp(i,j));
            }
            if(c[i][j]=='*')
                tot++;
        }
    }
    if(v.size()!=1){
        printf("NO\n");
    }
    else{
        int x=v[0].x,y=v[0].y;
        int cnt=0;
        for(int i=1;;i++){
            if(c[x][y+i]=='*')tot--;
            else break;
        }
        for(int i = 1;;i++){
            if(c[x][y-i]=='*')tot--;
            else break;
        }
        for(int i = 1;;i++){
            if(c[x+i][y]=='*')tot--;
            else break;
        }
        for(int i = 1;;i++){
            if(c[x-i][y]=='*')tot--;
            else break;
        }
        tot--;
        if(tot){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/