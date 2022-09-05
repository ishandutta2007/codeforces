#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int f[1200005];
int val[1200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[400005];
    set<pii> s;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        val[i]=a[i];
        f[i]=i;
        s.insert(mp(a[i],i));
    }
    int now=n+1;
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int k,w;
            scanf("%d %d",&k,&w);
            f[k]=now;
            f[now]=now;
            val[now]=w;
            
            s.insert(mp(w,now));
            now++;
        }
        else if(t==2){
            int k;
            scanf("%d",&k);
            printf("%d\n",val[Find(k)]);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            int mid=(l+r)/2;
            val[now]=l-1;
            f[now]=now;
            s.insert(mp(l-1,now));

            while(true){
                auto it=s.lower_bound(mp(l,0));
                if(it==s.end())break;
                if(it->x<=mid){
                    if(f[it->y]==it->y)f[it->y]=now;//printf("%d %d\n",it->y,now);
                    s.erase(it);
                }
                else{
                    break;
                }
            }
            now++;
            val[now]=r+1;
            f[now]=now;
            s.insert(mp(r+1,now));
             while(true){
                auto it=s.upper_bound(mp(mid,0));
                if(it==s.end())break;
                if(it->x<=r){
                    if(f[it->y]==it->y)f[it->y]=now;//printf("%d %d\n",it->y,now);
                    s.erase(it);
                }
                else{
                    break;
                }
            }
            now++;
        }
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
*/