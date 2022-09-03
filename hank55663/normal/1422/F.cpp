#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt;
struct node{
    node *l,*r;
    int last;
    int tag;
    node():l(NULL),r(NULL){
        cnt++;
        tag=1;
        last=0;
    }
}*root[100005];
node *Clone(node *n,int i){
    if(n->last==i)return n;
    node *res=new node();
    res->l=n->l;
    res->r=n->r;
    res->tag=n->tag;
    res->last=i;
    return res;
}
int mod=1e9+7;
void build(node *n,int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    n->l=new node();
    n->r=new node();
    build(n->l,l,mid);
    build(n->r,mid+1,r);
}
void add(node *n,int l,int r,int ql,int qr,LL k,int idx){
    if(ql>=l&&qr<=r){
        n->tag=n->tag*k%mod;
        return;
    }
    if(qr<l||ql>r)return;
    int mid=(ql+qr)/2;
    if(mid>=l)
    n->l=Clone(n->l,idx);
    if(mid+1<=r)
    n->r=Clone(n->r,idx);
    add(n->l,l,r,ql,mid,k,idx);
    add(n->r,l,r,mid+1,qr,k,idx);
}
LL query(node *n,int l,int ql,int qr){
    if(ql==qr)return n->tag;
    int mid=(ql+qr)/2;
    if(l<=mid){
        return query(n->l,l,ql,mid)*n->tag%mod;
    }
    else{
        return query(n->r,l,mid+1,qr)*n->tag%mod;
    }
}
vector<pii> v[200005];
int factor[200005];
LL pw[200005][30];
void solve(){
    for(int i = 2;i<200005;i++){
        if(factor[i]==0){
            for(int j = i;j<200005;j+=i){
                factor[j]=i;
            }
        }
        pw[i][0]=1;
        for(int j = 1;j<30;j++){
            pw[i][j]=pw[i][j-1]*i%mod;
        }
    }
    for(int i=1;i<200005;i++)v[i].pb(mp(0,1e9));
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    root[0]=new node();
    build(root[0],1,n);
    for(int i = 1;i<=n;i++){
        root[i]=Clone(root[i-1],i);
        int x=a[i];
        while(x!=1){
            int f=factor[x];
            int cnt=0;
            while(x%f==0){
                x/=f;
                cnt++;
            }
            add(root[i], v[f].back().x+1, i,1,n,pw[f][cnt],i);
            //printf("%d %d %d\n",v[f].back().x+1,i,pw[f][cnt]);

            while(v[f].size()&&v[f].back().y<=cnt){
                int d=cnt-v[f].back().y;
                int last=v[f].back().x;
                v[f].pop_back();
                add(root[i], v[f].back().x+1, last,1,n, pw[f][d],i);
                // printf("%d %d %d\n",v[f].back().x+1,last,pw[f][d]);
                //v[f].pop_back();
            }
            v[f].pb(mp(i,cnt));
        }
    }
    LL last=0;
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        //l=rand()%n+1;
        //r=rand()%n+1;
        l=(l+last)%n+1;
        r=(r+last)%n+1;
        if(l>r)swap(l,r);
        printf("%lld\n",last=query(root[r],l,1,n));
    }
   // printf("%d\n",cnt);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/