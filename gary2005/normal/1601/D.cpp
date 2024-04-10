/**
 *    author:  gary
 *    created: 25.10.2021 14:32:30
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=5e5+1;
int n,d;
int a[MAXN],s[MAXN];
int N;
struct seg
{
    int tree[1<<20],tag[1<<20];
    void buildtree(int n){
        N=1;
        while(N<n) N<<=1;
        rep(i,N+N) tree[i]=tag[i]=0;
    }
    void pd(int now){
        if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now],tree[now<<1]+=tag[now],tree[now<<1|1]+=tag[now];
        tag[now]=0;
    }
    void add(int a,int b,int val,int now,int l,int r){
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a) {
            tree[now]+=val;
            tag[now]+=val;
            return ;
        }
        pd(now);
        int mid=(l+r)>>1;
        add(a,b,val,now<<1,l,mid);
        add(a,b,val,now<<1|1,mid,r);
        tree[now]=max(tree[now<<1],tree[now<<1|1]);
    }
    int query(int a,int b,int now,int l,int r){
        if(r<=a||l>=b) return -INF;
        if(r<=b&&l>=a) {
            return tree[now];
        }
        int mid=(l+r)>>1;
        pd(now);
        return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}sgt;
inline int read(){
   int x=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x;
}
bool cmp(mp A,mp B){
    if(A.SEC==B.SEC) return A.FIR>B.FIR;
    return A.SEC<B.SEC;
}
int main(){
    scanf("%d%d",&n,&d);
    rb(i,1,n) s[i]=read(),a[i]=read();
    a[0]=d;
    sgt.buildtree(n);
    rb(i,1,n) sgt.add(i,i+1,-INF,1,1,N+1);
    vector<mp> v;
    int ans=0;
    rb(i,1,n){
        if(a[i]<=d){
            ans+=s[i]>=d;
        }
        else{
            if(s[i]>=d)
            v.PB(II(s[i],a[i]));
        }
    }
    sort(ALL(v),cmp);
    n=v.size();
    rb(i,1,n) tie(s[i],a[i])=v[i-1];
    vector<mp> vv;
    rb(i,1,n) vv.PB(II(s[i],i));
    sort(ALL(vv));
    rl(i,n,1){
        while(vv.size()&&vv.back().FIR>=a[i]){
            sgt.add(vv.back().SEC,vv.back().SEC+1,INF,1,1,N+1);
            vv.POB();
        }
        int dpval=sgt.query(1,n+1,1,1,N+1)+1;
        check_max(dpval,1);
        sgt.add(i,i+1,dpval,1,1,N+1);
        if(i!=n&&s[i]>=a[i+1]){
            int l=i+1,r=n+1;
            while(l<r-1){
                int mid=(l+r)>>1;
                if(a[mid]<=s[i]) l=mid;
                else r=mid;
            }
            sgt.add(i+1,r,1,1,1,N+1);
        }
    }
    while(vv.size()){
        sgt.add(vv.back().SEC,vv.back().SEC+1,INF,1,1,N+1);
        vv.POB();
    }
    cout<<ans+max(0,sgt.query(1,n+1,1,1,N+1))<<endl;
    return 0;
}