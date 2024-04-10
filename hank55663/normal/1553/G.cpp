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
int f[1000005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int cnt[1000005];
int prime[1000005];
vector<int> v[1000005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[200005];
    for(int i = 1;i<=1000000;i++)f[i]=i;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    fill(prime,prime+1000005,1);
    for(int i = 2;i<1000005;i++){
        if(prime[i]){
            for(int j = i*2;j<1000005;j+=i)prime[j]=0;
        }
    }
    for(int i = 2;i<1000005;i++){
        int last=-1;
        if(prime[i])
        for(int j = i;j<1000005;j+=i){
            //if(j==1000001)printf("%d\n",i);
            if(cnt[j]){
                if(last==-1)last=Find(j);
                else{
                    f[Find(j)]=last;
                }
            } 
        }
    }
    for(int i = 2;i<1000005;i++){
        int last=-1;
        if(prime[i]){
            for(int j=i;j<1000005;j+=i){
                if(cnt[j]){
                    last=Find(j);
                    break;
                }
            }
            for(int j = i;j<1000005;j+=i){
                if(cnt[j-1]){
                    v[j].pb(last);
                    //v[j].pb(Find(j-1));
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        v[a[i]+1].pb(Find(a[i]));
    }
    vector<pii> s;
    for(int i = 1;i<=1000001;i++){
        if(v[i].size()){
         //   printf("%d\n",i);
            sort(v[i].begin(),v[i].end());
            v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
            for(int j = 0;j<v[i].size();j++){
                for(int k = j+1;k<v[i].size();k++){
                    if(v[i][j]<v[i][k])
                    s.pb(mp(v[i][j],v[i][k]));
                    else{
                         s.pb(mp(v[i][k],v[i][j]));
                    }
                }
            }
        }
    }
   // for(auto it:v[8])printf("%d ",it);
  //  printf("\n");
  //  for(auto it:s)printf("%d %d\n",it.x,it.y);
  //  printf("\n");
    sort(s.begin(),s.end());
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        x=Find(a[x]);
        y=Find(a[y]);
       // printf("%d %d\n",x,y);
        if(x>y)swap(x,y);
        if(x==y)printf("0\n");
        else{
            auto it=lower_bound(s.begin(),s.end(),mp(x,y));
            if(it!=s.end()&&*it==mp(x,y))printf("1\n");
            else printf("2\n");
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/