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
const int mod=998244353;;
int val[200005];
int S[262144];
void add(int x,int k){
     // printf("add %d\n",x);
    x++;
  
    for(int i =x;i<262144;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    x++;
    int res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        val[x]^=x;
    }
    int ok[200005];
    pair<pii,int> p[200005];
    int q;
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(mp(l,r),i);
        ok[i]=0;
    }
    //sort(p,p+n);
    for(int i = 2;i<=262144;i<<=1){
        vector<pair<pii,int> > v;
        for(int j = 1;j<=q;j++){
            v.pb(mp(mp(p[j].x.x-1,p[j].x.x),-j));
            v.pb(mp(mp(p[j].x.y,p[j].x.x),j));
        }
        sort(v.begin(),v.end());
        int now=1;
        MEM(S);
        int tot[200005];
        MEM(tot);
        int sum=0;
        for(auto it:v){
            while(now<=it.x.x){
                if(val[now]){
              //      printf("??%d\n",val[now]);
                    add(val[now]%i,1);
                    sum++;
                }
                now++;
            }
            int l=i/2,r=i-1;
            l+=it.x.y;
            r+=it.x.y;
            
            l=(l%i+i)%i;
            r=(r%i+i)%i;
          //  printf("%d %d %d\n",l,r,it.x.y);
            if(l<=r){
                if(it.y>0){
                    tot[it.y]+=query(r)-query(l-1);
                }
                else{
                    tot[-it.y]-=query(r)-query(l-1);
                }
            }
            else{
                if(it.y>0){
                    tot[it.y]+=sum-(query(l-1)-query(r));
                }
                else{
                    tot[-it.y]-=sum-(query(l-1)-query(r));
                }
            }
        }
        for(int j=1;j<=q;j++){
           // printf("%d\n",tot[j]);
            if(tot[j]%2){
             //   printf("? %d\n",tot[j]);
                ok[j]=1;
            }
        }
    }
    for(int j =1;j<=q;j++){
        printf("%c","BA"[ok[j]]);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}