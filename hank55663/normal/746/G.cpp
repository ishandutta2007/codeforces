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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
int main(){
    int n,t,k;
    scanf("%d %d %d",&n,&t,&k);
    int a[300005];
    int ttmp[300005];
    MEM(a);
    a[0]=1;
    ttmp[0]=1;
    int tot=n-1;
   /*  for(int i=1;i<=t;i++){
        a[i]=1;
        tot--;
    }
    while(tot){
        a[rand()%t+1]++;
        tot--;
    }*/
    int l=0,r=0;
    for(int i = 1;i<=t;i++){
        scanf("%d",&a[i]);
       // printf("%d ",a[i]);
        l+=max(a[i-1]-a[i],0);
        ttmp[i]=a[i];
    }
    l+=a[t];
    r=n-t;
    int tmp=k;
  //  printf("%d %d\n",l,r);
    if(k>=l&&k<=r){
        k-=l;
        printf("%d\n",n);
        int last = 1,now=2;
        int degree[200005];
        MEM(degree);
        for(int i = 1;i<=t;i++){
            last+=max(ttmp[i-1]-ttmp[i],0);
            while(last+1!=now&&k){
                last++;
                k--;
            }
         //   printf("%d\n",k);
            int add=0;
            while(a[i]){
                printf("%d %d\n",last,now+add);
                degree[last]++;
                degree[now+add]++;
                add++;
                if(last+1!=now)
                    last++;
                a[i]--;
            }
            last=now;
            now+=add;
        }
        assert(now==n+1);
        for(int i = 2;i<=n;i++){
            if(degree[i]==1)
                tmp--;
        }
        assert(tmp==0);
    }
    else{
        printf("-1\n");
    }

}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */