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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL cross(LL x1,LL y1,LL x2,LL y2){
    return x1*y2-x2*y1;
}
LL cross(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3){
    return cross(x1-x3,y1-y3,x2-x3,y2-y3);
}
bool inter(LL x1,LL y1, LL x2,LL y2, LL x3,LL y3,LL x4,LL y4){
    if((cross(x2,y2,x3,y3,x1,y1)^cross(x2,y2,x4,y4,x1,y1))>=0)return false;
    if((cross(x3,y3,x1,y1,x4,y4)^cross(x3,y3,x2,y2,x4,y4))>=0)return false;
    return true;
}
int f[2005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    int x[2005],y[2005],a[2005];
    int ta[2005];
    for(int i = 1;i<=n;i++)f[i]=i;
    for(int i = 1;i<=n;i++){
        scanf("%d %d %d",&x[i],&y[i],&a[i]);
        ta[i]=a[i];
        int x=Find(i),y=Find(a[i]);
        f[x]=y;
    } 
    int st=0;
    for(int i = 1;i<=n;i++){
        if(a[i]!=i){
            st=i;
            break;
        }
    }
    if(st==0){
        printf("0\n");
        for(int i = 1;i<=n;i++){
            assert(a[i]==i);
        }
        return;
    }
    vector<pair<long double,int> > v;
    for(int i = 1;i<=n;i++){
        if(i!=st){
            v.pb(mp(atan2l(y[i]-y[st],x[i]-x[st]),i));
          //  cout<<v.back().x<<endl;
        }    
    }
    sort(v.begin(),v.end());
    vector<pii> ans;
    for(int i = 0;i<v.size();i++){
        int now=v[i].y,ne=v[(i+1)%v.size()].y;
           if(fmod(v[(i+1)%v.size()].x-v[i].x+2*pi,2*pi)>pi)continue;
        int fa=Find(now),fb=Find(ne);
       // printf("%d %d %d %d\n",now,ne,fa,fb);
        if(fa!=fb){
            swap(a[now],a[ne]);
            ans.pb(mp(now,ne));
            f[fa]=fb;
        }
    }
   // printf("%d %d\n",ans.size(),st);
    while(a[st]!=st){
        ans.pb(mp(st,a[st]));
        int xx=a[st];
        swap(a[st],a[xx]);
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d %d\n",it.x,it.y);
        swap(ta[it.x],ta[it.y]);
    }
    for(int i = 1;i<=n;i++){
        assert(ta[i]==i);
    }
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
}
/*
000
011
101
*/