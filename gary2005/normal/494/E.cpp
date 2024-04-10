/**
 *    author:  gary
 *    created: 26.03.2022 15:53:12
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
const int N=1<<20;
int n,m,k;
vector<pair<int,pair<mp,int> > > rect;
vector<int> useful;
int tree[N+N],tag[N+N];
void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        tag[now]+=val;
        if(tag[now]==0){
            if(now>=N) tree[now]=0;
            else tree[now]=tree[now<<1]^tree[now<<1|1];
        }
        else{
            tree[now]=useful[r-2]^useful[l-2];
        }
        return ;
    }
    int mid=(l+r)>>1;
    add(a,b,val,now<<1,l,mid);
    add(a,b,val,now<<1|1,mid,r);
    if(tag[now]) tree[now]=useful[r-2]^useful[l-2];
    else tree[now]=tree[now<<1]^tree[now<<1|1];
}
int main(){
     //freopen("b.in","r",stdin);
     //freopen("b.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    rb(i,1,m){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        rect.PB(II(a-1,II(II(b-1,d),1)));
        rect.PB(II(c,II(II(b-1,d),-1)));
        useful.PB(b-1);
        useful.PB(d);
    }
    sort(ALL(useful));
    useful.erase(unique(ALL(useful)),useful.end());
    sort(ALL(rect));
    int pre=0;
    int ans=0;
    for(auto it:rect){
        ans^=tree[1]&(it.first^pre);
        pre=it.first;
        add(lower_bound(ALL(useful),it.second.first.first)-useful.begin()+2,lower_bound(ALL(useful),it.second.first.second)-useful.begin()+2,it.second.second);
    }
    int tmp=1;
    while (tmp<=k)
    {
        tmp<<=1;
    }
    // ans^=ans>>1;
    if(ans&(tmp-1)) cout<<"Hamed";
    else cout<<"Malek";
    return 0;
}