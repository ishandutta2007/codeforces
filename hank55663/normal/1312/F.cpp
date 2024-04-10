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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int sg[6][6][6][100000][3];
int SG(int x,int y,int z,LL a,int op){
    if(a>100000){
        int aa[3]={x,y,z};
        sort(aa,aa+3);
        a%=(aa[0]+aa[2]);
        a+=(aa[0]+aa[2])*100;
    }
    if(a<=0)return 0;
    if(sg[x][y][z][a][op]!=-1)return sg[x][y][z][a][op];
    //printf("%d %d\n",a,op);
    int vis[4]={0,0,0};
    vis[SG(x,y,z,a-x,0)]=1;
    if(op!=1)
    vis[SG(x,y,z,a-y,1)]=1;
    if(op!=2)
    vis[SG(x,y,z,a-z,2)]=1;
    for(int i = 0;i<4;i++){
        if(!vis[i])
            return sg[x][y][z][a][op]=i;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    LL a[300005];
    MEMS(sg);
    while(t--){
        int n,x,y,z;
        scanf("%d %d %d %d",&n,&x,&y,&z);
        /*for(int i = 0;i<100;i++){
            printf("%d ",SG(x,y,z,i,0));
            if(i%(x+z)==0){
                printf("\n");
            }
        }
        printf("\n");*/
        
        int sg=0;
        for(int i = 0 ; i < n ; i++){
            scanf("%lld",&a[i]);
            if(a[i]>100000){
                a[i]=a[i]%((x+y)*(y+z)*(z+x))+((x+y)*(y+z)*(z+x))*100;
            }
            sg^=SG(x,y,z,a[i],0);
          //  printf("%d %d %d %d\n",SG(x,y,z,a[i],0),SG(x,y,z,a[i]-x,0),SG(x,y,z,a[i]-y,1),SG(x,y,z,a[i]-z,2));
        }
        int ans=0;
        for(int i = 0;i<n;i++){
            //printf("%d\n",sg,SG(x,y,z,a[i],0),sg(x,y,z,a[i]-x,0));
            if((sg^SG(x,y,z,a[i],0)^SG(x,y,z,a[i]-x,0))==0)ans++;//,printf("1");
            if((sg^SG(x,y,z,a[i],0)^SG(x,y,z,a[i]-y,1))==0)ans++;//,printf("2");//,printf("%d",2);
            if((sg^SG(x,y,z,a[i],0)^SG(x,y,z,a[i]-z,2))==0)ans++;//,printf("3");//,printf("%d",1);
           // printf("%d\n",i);
        }
        printf("%d\n",ans);
    }
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
1 3 4

*/