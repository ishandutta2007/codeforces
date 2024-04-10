#include<stdio.h>
#include<algorithm>
using namespace std;
int p[2100];
double dp[2100][2100][2][2];
int lt[2100];
int rt[2100];
int h;
int n;
double t;
double calc(int a,int b,int c,int d){
    if(a>b)return 0;
    if(dp[a][b][c][d]>-0.5){
        return dp[a][b][c][d];
    }
    if(a==b){
        int ld=h;
        int rd=h;
        if(c)ld-=max(0,(h*2-(p[a]-p[a-1])));
        else if(a)ld-=max(0,h-(p[a]-p[a-1]));
        if(d)rd-=max(0,(h*2-(p[a+1]-p[a])));
        else if(a<n-1)rd-=max(0,h-(p[a+1]-p[a]));
    //      printf("%d %d %d %d: %f\n",a,b,c,d,(double)ld*t+(double)rd*(1.0-t));
        return dp[a][b][c][d]=(double)ld*t+(double)rd*(1.0-t);
    }
    double ret=0;
    // right
    double tmp=0;
    int ld=h;
    if(c)ld-=max(0,(h*2-(p[a]-p[a-1])));
    else if(a)ld-=max(0,h-(p[a]-p[a-1]));
    tmp+=((double)ld+calc(a+1,b,0,d))*t;
    int rd=h+p[min(rt[a],b)]-p[a];
    if(d)rd-=max(0,(h*2-(p[b+1]-p[min(rt[a],b)])));
    else if(b<n-1)rd-=max(0,h-(p[b+1]-p[min(rt[a],b)]));
    tmp+=((double)rd+calc(min(rt[a],b)+1,b,1,d))*(1.0-t);
    ret+=tmp;
    // left
    tmp=0;
    rd=h;
    if(d)rd-=max(0,(h*2-(p[b+1]-p[b])));
    else if(b<n-1)rd-=max(0,h-(p[b+1]-p[b]));
    tmp+=((double)rd+calc(a,b-1,c,0))*(1.0-t);
    ld=h+p[b]-p[max(a,lt[b])];
    if(c)ld-=max(0,(h*2-(p[max(a,lt[b])]-p[a-1])));
    else if(a)ld-=max(0,h-(p[max(a,lt[b])]-p[a-1]));
    tmp+=((double)ld+calc(a,max(a,lt[b])-1,c,1))*t;
    //printf("%d %d %d %d: %f %f\n",a,b,c,d,ret/2,tmp/2);
    ret+=tmp;
    return dp[a][b][c][d]=ret/2;
}
int main(){
    int a,b;
    double c;
    scanf("%d%d%lf",&a,&b,&c);
    n=a;
    t=c;
    h=b;
    for(int i=0;i<a;i++){
        scanf("%d",p+i);
    }
    std::sort(p,p+a);
    int now=0;
    for(int i=0;i<a;i++){
        lt[i]=now;
        if(i<a-1&&p[i+1]-p[i]>=b)now=i+1;
    }
    now=a-1;
    for(int i=a-1;i>=0;i--){
        rt[i]=now;
        if(i>=0&&p[i]-p[i-1]>=b)now=i-1;
    }
    for(int i=0;i<2100;i++)for(int j=0;j<2100;j++){
    for(int k=0;k<2;k++)for(int l=0;l<2;l++)
        dp[i][j][k][l]=-1;
    }
    printf("%.12f\n",calc(0,a-1,0,0));
}