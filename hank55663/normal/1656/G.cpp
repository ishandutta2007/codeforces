#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
vector<int> v[200005];
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        f[i]=i;
    }
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    int cnt=0;
    for(int i = 1;i<=n;i++){
        if(v[i].size()%2==1){
            cnt++;
        }
    }
    if(cnt>1){
        printf("no\n");
    }
    else if(n%2==1&&v[a[(n+1)/2]].size()==1){
        printf("no\n");
    }
    else{
        printf("yes\n");
        int ans[200005];
        int l=1,r=n;
        for(int i = 1;i<=n;i++){
            if(v[i].size()%2==1){
                for(auto &it:v[i]){
                    if(it!=(n+1)/2){
                        swap(it,v[i].back());
                        break;
                    }
                }
                ans[(n+1)/2]=v[i].back();
                v[i].pop_back();
            }
            while(v[i].size()>=2){
                int a=v[i].back();
                v[i].pop_back();
                int b=v[i].back();
                v[i].pop_back();
                ans[l]=a;
                ans[r]=b;
                l++;
                r--;
            }
            /*if(v[i].size()==1){
                ans[(n+1)/2]=v[i].back();
                v[i].pop_back();
            }*/
        }
        for(int i = 1;i<=n;i++){
            int a=Find(i),b=Find(ans[i]);
           // printf("%d %d\n",a,b);
            if(f[a]!=f[b]){
                f[a]=b;
            }
        }
       //   for(int i = 1;i<=n;i++){
        //    printf("%d ",ans[i]);
       // }
       // printf("\n");
        l=1,r=n;
        while(l<r){
            int a=Find(l),b=Find(r);
           // printf("%d %d\n",a,b);
            if(f[a]!=f[b]){
                f[a]=b;
                swap(ans[l],ans[r]);
            }
            l++;
            r--;
        }
        for(int i = 2;i<=n;i++){
            int a=Find(1),b=Find(i);
            if(f[a]!=f[b]&&i!=(n-i+1)){
                f[a]=b;
                int x=i,y=n-i+1;
                swap(ans[1],ans[x]);
                swap(ans[n],ans[y]);
                swap(ans[x],ans[y]);
            }
        }
        for(int i = 1;i<=n;i++){
            assert(a[ans[i]]==a[ans[n-i+1]]);
        }
        for(int i = 1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/