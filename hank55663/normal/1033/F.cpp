#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 505
char c[1005];
int lim;
int w;
inline void FWT(int *x,int inv) {
    for(int i=1,cnt=w-1;i<lim;i<<=1,cnt--){
        if(c[cnt]=='o'||c[cnt]=='O'){
            for(int j=0;j<lim;++j)
                if(j&i)
                    x[j]= inv ? x[j]-x[j^i] : x[j]+x[j^i];
        }
        if(c[cnt]=='A'||c[cnt]=='a'){
            for(int j=0;j<lim;j+=(i<<1))
                for(int k=0;k<i;++k)
                    x[j+k]=inv ? x[j+k]-x[j+k+i] : x[j+k]+x[j+k+i];
        }
        if(c[cnt]=='X'||c[cnt]=='x'){
            for(int j=0;j<lim;j+=(i<<1))
                for(int k=0;k<i;++k) {
                    int y=x[j+k],z=x[j+k+i];
                    x[j+k]=inv ? (y+z)/2 : y+z;
                    x[j+k+i]=inv ? (y-z)/2 : y-z;
                }
        }
    }
}
int main(){
    int n,m;
    int a[5000];
    MEM(a);
    scanf("%d %d %d",&w,&n,&m);
    lim=1<<w;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    int b[5000];
    int k[5000];
    while(m--){
        scanf("%s",c);
        //printf("%d %d\n",a[0],a[1]);
        for(int i=0;i<lim;i++)
        k[i]=a[i];
        FWT(k,0);
        //printf("%d %d\n",a[0],a[1]);
        int ans=0;
        for(int i=0;i<w;i++){
            ans<<=1;
            if(c[i]>='a'&&c[i]<='z')
            ans++;
        }
        for(int i=0;i<lim;i++)
        b[i]=k[i]*k[i];
        FWT(b,1);
        printf("%d\n",b[ans]);
    }
}
/*
100
11
10
01

*/