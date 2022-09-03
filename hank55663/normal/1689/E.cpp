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
#define index Index
int f[2005];
int vis[2005];
int ok[2005];
int Size[2005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int Find2(int x){
    if(f[x]==x)return x;
    return Find2(f[x]);
}
int a[2005];
bool dc(int l,int r,int n){
  //  printf("q%d %d\n",l,r);
    if(l==r){
        MEM(vis);
        a[l]--;
        for(int i = 1;i<=n;i++){
            if(a[i]&a[l]){
               // printf("%d %d %d?\n",i,l,Find2(i));
                vis[Find2(i)]=1;
            }
        }
        int ok=1;
        for(int i = 1;i<=n;i++){
            if(f[i]==i&&!vis[i])ok=0;
            if(f[i]==i)vis[i]=0;
        }
        if(ok)return true;
        a[l]++;
        a[l]++;
        for(int i = 1;i<=n;i++){
            if(a[i]&a[l]){
              //  printf("%d %d %d??\n",i,l,Find2(i));
                vis[Find2(i)]=1;
            }
        }
        ok=1;
        for(int i = 1;i<=n;i++){
            if(f[i]==i&&!vis[i])ok=0;
            if(f[i]==i)vis[i]=0;
        }
      //  printf("\n");
        if(ok)return true;
        a[l]--;
        return false;
    }
    int mid=(l+r)/2;
    vector<pii> v;
    for(int i = l;i<=mid;i++){
        for(int j = 1;j<=n;j++){
            if((j<=mid||j>r)&&(a[i]&a[j])){
                int l=Find2(i),r=Find2(j);
              //  printf("%d %d %d %d\n",i,j,l,r);
                if(l!=r){
                    if(Size[l]<Size[r])swap(l,r);
                    v.pb(mp(l,r));
                    f[r]=l;
                    Size[l]+=Size[r];
                }
            }
        }
    }
    if(dc(mid+1,r,n))return true;
    reverse(v.begin(),v.end());
    for(auto it:v){
        Size[it.x]-=Size[it.y];
        f[it.y]=it.y;
       // printf("%d %d\n",it.x,it.y);
    }
     v.clear();
     for(int i = mid+1;i<=r;i++){
        for(int j = 1;j<=n;j++){
            if((j<l||j>mid)&&(a[i]&a[j])){
                int l=Find2(i),r=Find2(j);
           //  printf("%d %d %d %d\n",i,j,l,r);
                if(l!=r){
                    if(Size[l]<Size[r])swap(l,r);
                    v.pb(mp(l,r));
                    f[r]=l;
                    Size[l]+=Size[r];
                }
            }
        }
    }
    if(dc(l,mid,n))return true;
    reverse(v.begin(),v.end());
     for(auto it:v){
        Size[it.x]-=Size[it.y];
        f[it.y]=it.y;
      //   printf("%d %d\n",it.x,it.y);
    }
     v.clear();
     return false;
}
void solve(){
    int n;
    scanf("%d",&n);

    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        ok[i]=0;
        f[i]=i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[i]&a[j]){
                int x=Find(i),y=Find(j);
                f[x]=y;
            }
        }
    }
    int tot=0;
    set<int> s;
    for(int i = 1;i<=n;i++){
        if(a[i]&1){
            ok[Find(i)]=1;
          
        }  s.insert(Find(i));
    }
    if(s.size()==1){
        printf("0\n");
             for(int i = 1;i<=n;i++)printf("%d ",a[i]);
        printf("\n");
        return;
    }
    int add=0;
    for(int i = 1;i<=n;i++){
        if(f[i]==i&&!ok[i]){
            a[i]++;
            if(a[i]==1)
            add++;
            if(a[i]!=1)
            tot++;
        }
    }
    if(tot==0||tot==1){
        printf("%d\n",tot+add);
        for(int i = 1;i<=n;i++)printf("%d ",a[i]);
        printf("\n");
    }
    else{
        int Max=0;
        vector<int> v;
        for(int i = 1;i<=n;i++){
            if(f[i]==i&&!ok[i]){
                if(a[i]!=1)
                a[i]--;
            }
            int res=a[i]&-a[i];
            if(res>Max){
                Max=res;
                v.clear();
            }
            if(res==Max){
                v.pb(i);
            }
        }
        if(v.size()==1){
            a[v[0]]--;
            printf("%d\n",1+add);
            for(int i = 1;i<=n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
        else{
            for(int i = 1;i<=n;i++){
                f[i]=i;
                Size[i]=1;
            }
            if(dc(1,n,n)){
                 printf("%d\n",1+add);
                for(int i = 1;i<=n;i++){
                    printf("%d ",a[i]);
                }
                printf("\n");
            } else{
                a[v[0]]--;
                a[v[1]]++;
                  printf("%d\n",2+add);
                for(int i = 1;i<=n;i++){
                    printf("%d ",a[i]);
                }
                printf("\n");
            }
        }
    }
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}