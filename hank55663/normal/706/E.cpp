#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int vval[1000005];
int num[1000005][4];

int main(){ 
    int N,m,q;
    scanf("%d %d %d",&N,&m,&q);
    int cnt=1;
    for(int i = 1;i<=N;i++){
        for(int j=1;j<=m;j++){
            int x;//=rand();
            scanf("%d",&x);
            vval[cnt]=x;
            if(j!=m){
                num[cnt][1]=cnt+1;
                num[cnt+1][3]=cnt;
            }
            if(i!=N){
                num[cnt][2]=cnt+m;
                num[cnt+m][0]=cnt;
            }
            cnt++;
            
        }
    }/*{
        int val=1;
    while(num[val][0])val=num[val][0];
    while(num[val][3])val=num[val][3];
    for(int i = 1;i<=N;i++){
        int tmp=val;
        val=num[val][2];
        for(int j=1;j<=m;j++){
            printf("%d ",vval[tmp]);
            tmp=num[tmp][1];
        }
        printf("\n");
    }
    }*/
    while(q--){
        int a=1,b=50,c=2,d=100,h=999,w=1;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&h,&w);
        int val=1;
        while(num[val][0])val=num[val][0];
        while(num[val][3])val=num[val][3];
        int ta=val;
        for(int i=1;i<a;i++)ta=num[ta][2];
        for(int i=1;i<b;i++)ta=num[ta][1];
        int tb=val;
        for(int i=1;i<c;i++)tb=num[tb][2];
        for(int i=1;i<d;i++)tb=num[tb][1];
        num[num[ta][0]][2]=tb;
        num[num[tb][0]][2]=ta;
        swap(num[ta][0],num[tb][0]);
        for(int i=1;i<w;i++){
            ta=num[ta][1];
            tb=num[tb][1];
            num[num[ta][0]][2]=tb;
            num[num[tb][0]][2]=ta;
            swap(num[ta][0],num[tb][0]);
        }
        num[num[ta][1]][3]=tb;
        num[num[tb][1]][3]=ta;
        swap(num[ta][1],num[tb][1]);
        for(int i=1;i<h;i++){
            ta=num[ta][2];
            tb=num[tb][2];
            num[num[ta][1]][3]=tb;
            num[num[tb][1]][3]=ta;
            swap(num[ta][1],num[tb][1]);
        }
        num[num[ta][2]][0]=tb;
        num[num[tb][2]][0]=ta;
        swap(num[ta][2],num[tb][2]);
        for(int i = 1;i<w;i++){
            ta=num[ta][3];
            tb=num[tb][3];
            num[num[ta][2]][0]=tb;
            num[num[tb][2]][0]=ta;
            swap(num[ta][2],num[tb][2]);
        }
        num[num[ta][3]][1]=tb;
        num[num[tb][3]][1]=ta;
        swap(num[ta][3],num[tb][3]);
        for(int i=1;i<h;i++){
            ta=num[ta][0];
            tb=num[tb][0];
            num[num[ta][3]][1]=tb;
            num[num[tb][3]][1]=ta;
            swap(num[ta][3],num[tb][3]);
        }
        val=1;
      /*  printf("?\n");
        while(num[val][0])val=num[val][0],printf("%d\n",val),getchar();
        while(num[val][3])val=num[val][3];
        for(int i = 1;i<=N;i++){
            int tmp=val;
            val=num[val][2];
            for(int j=1;j<=m;j++){
                printf("%d ",vval[tmp]);
                tmp=num[tmp][1];
            }
            printf("\n");
        }*/
    }
    int val=1;
    while(num[val][0])val=num[val][0];
    while(num[val][3])val=num[val][3];
    for(int i = 1;i<=N;i++){
        int tmp=val;
        val=num[val][2];
        for(int j=1;j<=m;j++){
            printf("%d ",vval[tmp]);
            tmp=num[tmp][1];
        }
        printf("\n");
    }
}
/**/