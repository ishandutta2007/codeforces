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
#define MXN 10005
#define less Less
int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int c[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&c[i]);
    pii p[100005];
    for(int i = 0;i<n;i++)
        p[i]=mp(c[i],a[i]);
    sort(p,p+n);
    int last=-1e9-1;
    int b[100005];
    for(int i = 0;i<n;i++){
        b[i]=max(last+1+p[i].y,l);
        if(b[i]>r){
            printf("-1\n");
            return 0;
        }
        last=b[i]-p[i].y;
       // printf("%d %d\n",b[i],last);
    }
    for(int i = 0;i<n;i++){
        printf("%d ",b[c[i]-1]);
    }
    printf("\n");
    return 0;
}