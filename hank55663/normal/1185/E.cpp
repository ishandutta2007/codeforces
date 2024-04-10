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
char c[2005][2005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> v[26];
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j = 1;j<=m;j++){
            if(c[i][j]!='.')
                v[c[i][j]-'a'].pb(mp(i,j));
        }
    }
    int last=-1;
    int x1[26],y1[26],x2[26],y2[26];
    fill(x1,x1+26,-1);
    fill(y1,y1+26,-1);
    fill(x2,x2+26,-1);
    fill(y2,y2+26,-1);
    for(int i = 0;i<26;i++){
        if(v[i].size()){
            if(v[i].size()==1){
                x2[i]=x1[i]=v[i][0].x;
                y2[i]=y1[i]=v[i][0].y;   
                c[v[i][0].x][v[i][0].y]='.';
            }
            else{
                if(v[i][0].x==v[i].back().x){
                    for(int j=v[i][0].y;j<=v[i].back().y;j++){
                        if(c[v[i][0].x][j]=='.'){
                            printf("NO\n");
                            return;
                        }
                        if(c[v[i][0].x][j]=='a'+i){
                            c[v[i][0].x][j]='.';
                        }
                    }
                    x1[i]=x2[i]=v[i][0].x;
                    y1[i]=v[i][0].y;
                    y2[i]=v[i].back().y;
                }
                else if(v[i][0].y==v[i].back().y){
                    for(int j=v[i][0].x;j<=v[i].back().x;j++){
                        if(c[j][v[i][0].y]=='.'){
                            printf("NO\n");
                            return;
                        }
                        if(c[j][v[i][0].y]=='a'+i){
                            c[j][v[i][0].y]='.';
                        }
                    }
                    y1[i]=y2[i]=v[i][0].y;
                    x1[i]=v[i][0].x;
                    x2[i]=v[i].back().x;
                }
                else{
                    printf("NO\n");
                    return ;
                }
            }
            last=i;
        }
    }
    for(int i = 1;i<=n;i++)
        for(int j =1;j<=m;j++){
            if(c[i][j]!='.'){
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
    printf("%d\n",last+1);
    for(int i=0;i<=last;i++){
        if(x1[i]==-1){
            printf("%d %d %d %d\n",x1[last],y1[last],x2[last],y2[last]);
        }
        else{
            printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();   
    }
}
/*
m3->m2->m->m4
0 1 2 3 4
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/