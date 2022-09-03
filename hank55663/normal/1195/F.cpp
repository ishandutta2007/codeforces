#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define N (1<<20)
pii operator+(const pii &p,const pii &q){
    return {p.x+q.x,p.y+q.y};
}
pii operator-(const pii &p){
    return {-p.x,-p.y};
}
pii operator-(const pii &p,const pii &q){
    return p+(-q);
}
vector<pii> v[100005];
int in[100005];
int cnt[300005];
int a[300005];
int Size=550;
bool cmp(const pair<pii,int> &p,const pair<pii,int> &q){
    if(p.x.x/Size==q.x.x/Size){
        return p.x.y<q.x.y;
    }
    else{
        return p.x.x<q.x.x;
    }
}
int main(){
    map<pii,int> m;
    int n;
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        int k;
        scanf("%d",&k);
        vector<pii> tmp;
        for(int j=0;j<k;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            tmp.pb(mp(x,y));
        }
        for(int j = 0;j<k;j++){
            pii p=tmp[(j+1)%k]-tmp[j];
            int gcd=abs(__gcd(p.x,p.y));
            //printf("%d\n",gcd);
            p.x/=gcd;
            p.y/=gcd;
            v[i].pb(p);
            m[p];
        }
    }
    int Index=0;
    for(auto &it:m){
        it.y=Index++;
    }
    in[0]=0;
    for(int i = 0;i<n;i++){
        in[i+1]=in[i];
        for(auto it:v[i]){
            a[in[i+1]]=m[it];
            in[i+1]++;
        }
    }
    pair<pii,int> que[100005];
    int q;
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        que[i]=mp(mp(in[l],in[r]-1),i);
    }
    
    sort(que,que+q,cmp);
    int sum=0;
    int ans[100005];
    int l=0,r=-1;
    for(int i=0;i<q;i++){
        while(l>que[i].x.x){
            l--;cnt[a[l]]++;
            if(cnt[a[l]]==1)sum++;
        }
        while(r<que[i].x.y){
            r++;
            cnt[a[r]]++;
            if(cnt[a[r]]==1)sum++;
        }
        while(l<que[i].x.x){
            cnt[a[l]]--;
            if(cnt[a[l]]==0)sum--;
            l++;
        }
        while(r>que[i].x.y){
            cnt[a[r]]--;
            if(cnt[a[r]]==0)sum--;
            r--;
        }
        ans[que[i].y]=sum;
    }
    for(int i = 0;i<q;i++)
        printf("%d\n",ans[i]);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/