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
pair<pii,int> p[200005];
int S[200005];
void add(int x,int k){
    x++;
    for(int i=x;i<200005;i+=i&-i){
        S[i]=max(S[i],k);
    }
}
int query(int x){
    int res=0;
    x++;
    for(int i = x;i>0;i-=i&-i){
        res=max(res,S[i]);
    }
    return res;
}
void reset(int x){
    x++;
    for(int i =x;i<200005;i+=i&-i){
        S[i]=0;
    }
}
vector<pair<pii,int> > v;
void solve(int l,int r){
    if(l==r){
        if(p[l].x.y>=0)p[l].y=max(p[l].y,1);
        return;
    }
    int mid=(l+r)/2;
    solve(l,mid);
    v.clear();
    for(int i = mid+1;i<=r;i++){
        v.pb(mp(p[i].x,i));
    }
    sort(v.begin(),v.end());
    int a=l,b=0;
    while(a!=mid+1||b!=v.size()){
        if(a==mid+1){
            int x=query(v[b].x.y);
            if(p[v[b].y].x.y>=0)
            p[v[b].y].y=max(p[v[b].y].y,x+1);
            b++;
        }
        else if(b==v.size()){
            break;
        }
        else if(p[a].x.x<v[b].x.x){
            if(p[a].x.y>=0)add(p[a].x.y,p[a].y);
            a++;
        }
        else{
            int x=query(v[b].x.y);
            if(p[v[b].y].x.y>=0)
            p[v[b].y].y=max(p[v[b].y].y,x+1);
            b++;
        }
    }
    for(int i = l;i<=mid;i++){
        if(p[i].x.y>=0)reset(p[i].x.y);
    }
    solve(mid+1,r);
    sort(p+l,p+r+1);
}
void solve(){
    int n;
    scanf("%d",&n);

    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i].x.x);
        p[i].x.y=i-p[i].x.x;
    }
    solve(1,n);
    int ans=0;
    for(int i = 1;i<=n;i++)ans=max(ans,p[i].y);
    for(int i = 1;i<=n;i++){
     //   printf("%d %d\n",p[i].x.x,p[i].y);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/