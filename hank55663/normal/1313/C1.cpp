#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 10000
LL S[500005],cnt[500005];
void add(int x,int k,LL *s){
    for(int i = x;i<500005;i+=i&-i){
        s[i]+=k;
    }
}
LL query(int x,LL *s){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
LL l[500005],r[500005];
int main(){
    int n;
    scanf("%d",&n);
    int a[500005];
    map<LL,LL> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    //    m[a[i]];
    }
   /* int index=0;
    for(auto& it:m)
        it.y=++index;*/
    //set<pii> s;
    LL now=0;
    //[100005];
    for(int i = 1;i<=n;i++){
        m[a[i]]++;
        while(m.rbegin()->x!=a[i]){
            now+=(m.rbegin()->x-a[i])*(m.rbegin()->y);
            pll p=*m.rbegin();
            m.erase(p.x);
            m[a[i]]+=p.y;
        }
        l[i]=now;
    }
    m.clear();
    for(int i = n;i>=1;i--){
        m[a[i]]++;
        while(m.rbegin()->x!=a[i]){
            now+=(m.rbegin()->x-a[i])*(m.rbegin()->y);
            pll p=*m.rbegin();
            m.erase(p.x);
            m[a[i]]+=p.y;
        }
        l[i]+=now;
    }
    LL Min=1e18,Mini=0;
    for(int i=  1;i<=n;i++){
        if(l[i]<Min){
            Min=l[i];
            Mini=i;
        }
    }
    now=1e9;
    for(int i=Mini;i>=1;i--){
        now=min((int)now,a[i]);
        a[i]=min(a[i],(int)now);
    }
    now=1e9;
    for(int i=Mini;i<=n;i++){
        now=min((int)now,a[i]);
        a[i]=min(a[i],(int)now);
    }
    for(int i = 1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}