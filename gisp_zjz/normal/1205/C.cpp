#include<bits/stdc++.h>
using namespace std;
int n,a[55][55],b[55][55],o,flag,pos,offset;
int ask(int x,int y,int xx,int yy){
    x+=offset; y+=offset;
    xx+=offset; yy+=offset;
    printf("? %d %d %d %d\n",x,y,xx,yy);
    fflush(stdout);
    scanf("%d",&o);
    return !o;
}
bool valid(int x,int y){
    if (x<1||x>n||y<1||y>n) return 0;
    if (b[x][y]!=-1) return 0;
    return 1;
}
bool dfs(int x,int y){
    if (valid(x-2,y)) b[x-2][y]=ask(x-2,y,x,y)^b[x][y],dfs(x-2,y);
    if (valid(x-1,y-1)) b[x-1][y-1]=ask(x-1,y-1,x,y)^b[x][y],dfs(x-1,y-1);
    if (valid(x,y-2)) b[x][y-2]=ask(x,y-2,x,y)^b[x][y],dfs(x,y-2);

    if (valid(x+2,y)) b[x+2][y]=ask(x,y,x+2,y)^b[x][y],dfs(x+2,y);
    if (valid(x+1,y+1)) b[x+1][y+1]=ask(x,y,x+1,y+1)^b[x][y],dfs(x+1,y+1);
    if (valid(x,y+2)) b[x][y+2]=ask(x,y,x,y+2)^b[x][y],dfs(x,y+2);
}
int main(){
    cin >> n;
    memset(b,-1,sizeof(b));
    b[1][1]=1; b[n][n]=0;
    for (int i=2;i<n;i++) b[i][i]=ask(i-1,i-1,i,i)^b[i-1][i-1];
    pos=-1;
    for (int i=1;i<=n-2;i+=2) if (b[i][i]==1&&b[i+2][i+2]==0) {pos=i;break;}
    a[1][1]=b[pos][pos];
    a[2][2]=b[pos+1][pos+1];
    a[3][3]=b[pos+2][pos+2];
    offset=pos-1;
    a[3][1]=ask(1,1,3,1)^a[1][1];
    a[1][3]=ask(1,1,1,3)^a[1][1];
    flag=ask(2,1,3,2);
    if (!flag){
        if (a[3][1]==1){
            if (!ask(1,1,3,2)){
                a[2][1]=a[3][2]=1;
            } else {
                a[2][1]=a[3][2]=0;
            }
        } else {
            if (!ask(2,1,3,3)){
                a[2][1]=a[3][2]=0;
            } else {
                a[2][1]=a[3][2]=1;
            }
        }
    } else {
        if (a[3][1]==1){
            if (!ask(2,1,3,3)){
                a[2][1]=0; a[3][2]=1;
            } else {
                a[2][1]=1; a[3][2]=0;
            }
        } else {
            if (!ask(1,1,3,2)){
                a[2][1]=0; a[3][2]=1;
            } else {
                a[2][1]=1; a[3][2]=0;
            }
        }
    }
    a[2][3]=ask(2,1,2,3)^a[2][1];
    a[1][2]=ask(1,2,2,3)^a[2][3];
    for (int i=0;i<=2;i++)
        for (int j=0;j<=2;j++)
            b[pos+i][pos+j]=a[1+i][1+j];
    offset=0;
    for (int i=0;i<=2;i++)
        for (int j=0;j<=2;j++)
            dfs(pos+i,pos+j);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            assert(b[i][j]!=-1);
    puts("!");
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d",b[i][j]);
        puts("");
    }
    return 0;
}