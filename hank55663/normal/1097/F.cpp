
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
bitset<7001> b[7001];
bitset<7001> lcm[7001];
bitset<7001> s[100005];
int mobe[7001];
int main(){
    fill(mobe+1,mobe+7001,1);
    for(int i=2;i<7001;i++){
        for(int j=2;j<i;j++){
            if(i%j==0&&(i/j)%j==0){
                mobe[i]=0;
                break;
            }
        }
     //   printf("%d ",mobe[i]);
    }
  //  printf("\n");
    for(int i=1;i<=7000;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                b[i][j]=1;
            }
        }
        for(int j=1;i*j<=7000;j++){
            if(mobe[j])
            lcm[i][i*j]=1;
        }
    }
    int n,q;
    scanf("%d %d",&n,&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,v;
            scanf("%d %d",&x,&v);
            s[x]=b[v];
        }
        else if(op==2){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            s[x]=s[y]^s[z];
        }
        else if(op==3){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            s[x]=s[y]&s[z];
        }
        else{
            int x,v;
            scanf("%d %d",&x,&v);
            bitset<7001> temp=s[x]&lcm[v];
            int ans=temp.count()&1;
            printf("%d",ans);
        }
    }
}