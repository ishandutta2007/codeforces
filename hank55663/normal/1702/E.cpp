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
#define double long double
using namespace std;
int f[200005];
int Size[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int cnt[200005];
void solve(){  
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)f[i]=i,Size[i]=0,cnt[i]=0;
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        cnt[x]++;
        cnt[y]++;
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            f[fx]=fy;
            Size[fy]+=Size[fx];
        }
        Size[fy]++;
    }
    for(int i = 1;i<=n;i++){
        if(cnt[i]!=2){
            printf("NO\n");
            return;
        }
        if(Size[Find(i)]&1){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/