#include<cstdio>
bool s[2048][2048];
int a,b,c,d,n,m,e,x,y;
void dfs(int i,int j){
    s[i][j]=0;++m;
    if(i>a||i==a&&j<b){a=i,b=j;}
    if(i<c||i==c&&j>d){c=i,d=j;}
    if(i+1<n&&s[i+1][j])dfs(i+1,j);
    if(j+1<n&&s[i][j+1])dfs(i,j+1);
    if(j&&s[i][j-1])dfs(i,j-1);
    if(i&&s[i-1][j])dfs(i-1,j);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j){
        scanf("%d",&e);
        s[i][j]=e;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)if(s[i][j]){
            m=0;a=-1;b=20000;c=20000;d=-1;
            dfs(i,j);
            e=(a-c)*(a-c)+(b-d)*(b-d);
            if(e*0.63<m)++x;else ++y;
        }
    printf("%d %d\n",x,y);
}