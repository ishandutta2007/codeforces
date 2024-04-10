#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int S[1000005];
void add(int x,int k){
    x++;
    for(int i =x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    x++;
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    pair<int,pii> yy[100005],xx[100005];
    int y[100005],lx[100005],rx[100005];
    for(int i = 1;i<=n;i++)scanf("%d %d %d",&yy[i].x,&yy[i].y.x,&yy[i].y.y);
    int x[100005],ly[100005],ry[100005];
    for(int i = 1;i<=m;i++)scanf("%d %d %d",&xx[i].x,&xx[i].y.x,&xx[i].y.y);
    sort(xx+1,xx+m+1);
    sort(yy+1,yy+n+1);
    set<pii> s;
    for(int i = 1;i<=n;i++){
        y[i]=yy[i].x;
        tie(lx[i],rx[i])=yy[i].y;
        s.insert(mp(lx[i],y[i]));
        s.insert(mp(rx[i],y[i]));
    }
    for(int i = 1;i<=m;i++){
        x[i]=xx[i].x;
        tie(ly[i],ry[i])=xx[i].y;
        s.insert(mp(x[i],ly[i]));
        s.insert(mp(x[i],ry[i]));

    }
    y[0]=0,lx[0]=0,rx[0]=1000000;
    y[n+1]=1000000,lx[n+1]=0,rx[n+1]=1000000;
    n=n+2;
    x[0]=0,ly[0]=0,ry[0]=1000000;
    x[m+1]=1000000,ly[m+1]=0,ry[m+1]=1000000;
    m=m+2;
    s.insert(mp(0,0));
    s.insert(mp(0,1000000));
    s.insert(mp(1000000,0));
    s.insert(mp(1000000,1000000));
    /*node*/
    LL cn=0;
    vector<pair<int,pii> > v;
    for(int i = 0;i<n;i++){
        v.pb(mp(lx[i]+1,mp(y[i],1)));
        v.pb(mp(rx[i],mp(y[i],-1)));
    }
    sort(v.begin(),v.end());
    int now=0;
    for(int i = 0;i<m;i++){
        while(now!=v.size()&&v[now].x<=x[i]){
            add(v[now].y.x,v[now].y.y);
           //printf("node add%d %d\n",v[now].y.x,v[now].y.y);
            now++;
           
        }
        cn+=query(ry[i]-1)-query(ly[i]);
       // printf("node q%d %d %d %d\n",x[i],ly[i],ry[i],query(ry[i]-1)-query(ly[i]));
    }
    cn+=s.size();
  //  for(auto it:s)printf("%d %d\n",it.x,it.y);
   // printf("! %d\n",s.size());
    /*edge*/;
    LL ce=0;
    MEM(S);
    now=0;
    v.clear();
    for(int i = 0;i<n;i++){
        v.pb(mp(lx[i],mp(y[i],1)));
        v.pb(mp(rx[i]+1,mp(y[i],-1)));
    }
        sort(v.begin(),v.end());
    for(int i = 0;i<m;i++){
        while(now!=v.size()&&v[now].x<=x[i]){
            add(v[now].y.x,v[now].y.y);
         //   printf("add%d %d\n",v[now].y.x,v[now].y.y);
            now++;
        }
        ce+=query(ry[i]-1)-query(ly[i])+1;
      //  printf("q%d %d %d %d\n",x[i],ly[i],ry[i],query(ry[i]-1)-query(ly[i])+1);
    }
    v.clear();
    for(int i = 0;i<m;i++){
        v.pb(mp(ly[i],mp(x[i],1)));
        v.pb(mp(ry[i]+1,mp(x[i],-1)));
    }
    sort(v.begin(),v.end());
    now=0;
     MEM(S);
    // printf("\n");
    for(int i = 0;i<n;i++){
        while(now!=v.size()&&v[now].x<=y[i]){
            add(v[now].y.x,v[now].y.y);
           // printf("add%d %d\n",v[now].y.x,v[now].y.y);
            now++;
        }
        ce+=query(rx[i]-1)-query(lx[i])+1;
      //  printf("q%d %d %d %d\n",y[i],lx[i],rx[i],query(rx[i]-1)-query(lx[i])+1);
    }
  //  printf("%lld %lld\n",ce,cn);
    printf("%lld\n",ce-cn+1);
}
int main()
{
    int t=1;
    //scanf("%d",&t);
    int T=1;
    while(t--){
        solve();
    }
}