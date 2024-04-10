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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int Max;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(-1e9){};
}*root;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r)return -1e9;
    return max(query(n->l,l,r),query(n->r,l,r));
}
LL t[200005],a[200005],v;
int aa[600005];
int dp[200005];
void dc(int l,int r){
  
    if(l==r){
        if(t[l]*v>=abs(a[l])){
            dp[l]=max(dp[l],1);
        }
        else{
            dp[l]=-1e9;
        }
      //  printf("dp[%d]:%d %lld %lld\n",l,dp[l],t[l],a[l]);
        return;
    }
    int mid=(l+r)/2;
    dc(l,mid);
    if(r-l<=400){
        for(int j = mid+1;j<=r;j++){
            for(int i =l;i<=mid;i++){
                if((t[j]-t[i])*v>=abs(a[j]-a[i])){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
    }
    else{
        //  printf("%d %d\n",l,r);
       // map<LL,int> m;
        vector<LL> m;
        for(int i  =l;i<=r;i++){
            LL l=a[i]-v*abs(t[mid+1]-t[i]),r=a[i]+v*abs(t[mid+1]-t[i]);
            m.pb(l);
            m.pb(r+1);
            //m[l];
            //m[r+1];
        }
        sort(m.begin(),m.end());
        m.resize(unique(m.begin(),m.end())-m.begin());
        int index=0;
        //for(auto &it:m)it.y=++index;
        root=new node(1,m.size());

        vector<pair<pii,int> > vv;
        for(int i = l;i<=mid;i++){
            LL l=a[i]-v*abs(t[mid+1]-t[i]),r=a[i]+v*abs(t[mid+1]-t[i]);
            l=lower_bound(m.begin(),m.end(),l)-m.begin()+1;
            r=lower_bound(m.begin(),m.end(),r+1)-m.begin()+1;//m[r+1];
            vv.pb(mp(mp(l,dp[i]),1));
            vv.pb(mp(mp(r,dp[i]),-1));
          //  printf("%d %d %d\n",l,r-1,dp[i]);
        }
        sort(vv.begin(),vv.end());
        multiset<int> s;
        s.insert(-1e9);
        int now=0;
        index=m.size();
        for(int i = 1;i<=index;i++){
            while(now!=vv.size()&&vv[now].x.x==i){
                if(vv[now].y==1)s.insert(vv[now].x.y);
                else s.erase(s.find(vv[now].x.y));
                now++;
            }
            aa[i]=*s.rbegin();
        }
        build(root,aa);
        for(int i = mid+1;i<=r;i++){
            LL l=a[i]-v*abs(t[mid+1]-t[i]),r=a[i]+v*abs(t[mid+1]-t[i]);
            l=lower_bound(m.begin(),m.end(),l)-m.begin()+1;
            r=lower_bound(m.begin(),m.end(),r+1)-m.begin();
           // printf("q %d %d %d\n",l,r,query(root,l,r));
            dp[i]=max(dp[i],query(root,l,r)+1);
        }
    }
    dc(mid+1,r);
}
void solve(){
    int n;
    scanf("%d %lld",&n,&v);
  //  int t[200005],a[200005];
  //  t[0]=rand()%100;
    for(int i = 0;i<n;i++){
        scanf("%lld",&t[i]);
       // t[i]=rand()%100+t[i-1]+1;
    }
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
       // a[i]=rand()%2000000001-1000000000;
    }
    dc(0,n-1);
    int ans=0;
    for(int i = 0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

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