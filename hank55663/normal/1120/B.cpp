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
char a[100005];
char b[100005];
int tempa[100005];
int tempb[100005];
vector<pii> v;
int n;
void add(int x,int s){
    if(x==n){
        printf("-1\n");
        exit(0);
    }
    if(v.size()==100000)
    return ;
    a[x]+=s;
    a[x+1]+=s;
    if(a[x+1]<'0'){
        add(x+1,1);
    }
    if(a[x+1]>'9'){
        add(x+1,-1);
    }
    if(v.size()<100000)
    v.pb(mp(x+1,s));
    else{
        return ;
    }
}
int main(){
    scanf("%d",&n);
    /*for(int i=0;i<n;i++)
    a[i]=rand()%10+'0';
    for(int i=0;i<n;i++)
    b[i]=rand()%10+'0';*/
    scanf("%s",a);
    scanf("%s",b);
    LL ans=0;
    for(int i=0;i<n;i++)
    tempa[i]=a[i]-'0';
    for(int i=0;i<n;i++)
    tempb[i]=b[i]-'0';
    for(int i=0;i<n;i++){
        if(tempa[i]>tempb[i]){
            ans+=tempa[i]-tempb[i];
            tempa[i+1]-=tempa[i]-tempb[i];
            tempa[i]=tempb[i];
        }
        else{
            ans+=tempb[i]-tempa[i];
            tempa[i+1]-=tempa[i]-tempb[i];
            tempa[i]=tempb[i];
        }
    }
   // a[n]=b[n]=0;
    int odd=0,even=0;
    int odd1=0,even1=0;
    for(int i=0;a[i]!=0;i++){
        if(i&1){
            odd+=a[i]-'0';
        }
        else{
            even+=a[i]-'0';
        }
    }
    for(int i=0;i<n;i++){
        if(i&1){
            odd1+=b[i]-'0';
        }
        else{
            even1+=b[i]-'0';
        }
    }
    if(odd-even!=odd1-even1){
        printf("-1\n");
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            while(a[i]>b[i]){
                if(v.size()==100000)
                break;
                add(i,-1);
            }
            while(a[i]<b[i]){
                if(v.size()==100000)
                break;
                add(i,1);
            }
        }
    }
    printf("%lld\n",ans);
    for(auto it:v){
        printf("%d %d\n",it.x,it.y);
    }
}