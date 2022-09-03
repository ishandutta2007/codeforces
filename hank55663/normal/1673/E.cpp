#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
int Next[1048577];
int ok[1048577];
int val2[1048577];
int val[1048577];
    int vval[1048577];
void solve(){
    int n,k;
    int b[1049577];

    scanf("%d %d",&n,&k);
    LL tot=1;
    for(int i = 0;i<n;i++){
        scanf("%d",&b[i]);
        
 
        vval[i]=1<<min(b[i],20);
        if(i==0)
        tot=tot*b[i];
        else
        tot=tot*vval[i];
        if(tot>1e7)tot=1e7;
    }
    int tk=max(k-1,0);
    val2[tk]=1;
    for(int j = tk+1;j<=n-1;j++){
        if(tk==0)val2[j]=0;
        else
        val2[j]=(((j-1)&(tk-1))==(tk-1));
    }
   // printf("%d\n",tot);
    if(k==0&&tot<1048577)ok[tot]^=1;
    //for(int t=0;t<2;t++){
    tot=1;
    for(int i=0;i<n-1;i++){
        if(i==0)
        tot=tot*b[i];
        else tot=tot*vval[i];
        if(tot>=1048577){
            break;
        }
        ok[tot]^=val2[n-1-i-1];
        //printf("%d %d %d\n",tot,n-1-i-1,k-1);
    }
   // reverse(b,b+n);
   // }
    MEM(val);
    tk=max(k-2,0);
    val[tk]=1;
    for(int j = tk+1;j<=n-1;j++){
        if(tk==0)val[j]=0;
        else
        val[j]=(((j-1)&(tk-1))==(tk-1));
       // val[j]^=val[j-1];
    }
    
    for(int i = 1;i<n;i++){
        tot=b[i];
        int cnt=n-1-2;
        if(i!=n-1){
            //  printf("%d %d %d\n",tot,cnt,i);
            if(val[cnt])ok[tot]^=1;
        }
        else{
            //  printf("%d %d %d\n",tot,cnt,i);
            if(val2[cnt+1])ok[tot]^=1;
        }
        for(int j = i+1;j<n;j++){
            tot=tot*vval[j];
            if(tot>=1048577)break;
            cnt--;
           // printf("%d %d %d\n",tot,cnt,j);
            if(j!=n-1)
            ok[tot]^=val[cnt];
            else
            ok[tot]^=val2[cnt+1];
        }
    }
    int ook=0;
    for(int j = (1<<20)-1;j>=0;j--){
        if(ok[j])ook=1;
        if(ook)
        printf("%d",ok[j]);
    }
    if(!ook)printf("0");
    printf("\n");
}
int main(){
    srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/