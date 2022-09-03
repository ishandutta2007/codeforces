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
int main(){
    int n;
    scanf("%d",&n);
    int Max=1e9,Min=n-2;
    int cnt=0;
    int Maxnum;
    while(Max>=Min){
        int mid=(Max+Min)/2;
        printf("> %d\n",mid);
        fflush(stdout);
        int r;
        scanf("%d",&r);
        if(r==1)
        Min=mid+1;
        else{
            Maxnum=mid;
            Max=mid-1;
        }
        cnt++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    v.pb(i);
    srand(time(NULL));
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(),v.end(),g);
    vector<int> vv;
    for(int i=0;i+cnt<59&&i<v.size();i++){
        printf("? %d\n",v[i]);
        fflush(stdout);
        int r;
        scanf("%d",&r);
        assert(r!=-1);
        vv.pb(r);
    }
    vv.pb(Maxnum);
    sort(vv.begin(),vv.end());
    int gcd=(vv[1]-vv[0]);
    for(int i=2;i<vv.size();i++){
        gcd=__gcd(gcd,vv[i]-vv[i-1]);
    }
    assert(Maxnum-gcd*(n-1)>=0);
    printf("! %d %d\n",Maxnum-gcd*(n-1),gcd);
    return 0;
}