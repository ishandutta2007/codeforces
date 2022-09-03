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
int isprime[200005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    map<int,vector<LL> > m;
    multiset<LL> s;
    for(int i = 2;i<=n;i++){
        if(isprime[i]&&n%i==0){
            int b=n/i;
            m[b].resize(b);
            for(int j=0;j<n;j++){
                m[b][j%b]+=a[j]*1ll*b;
            }
            for(auto it:m[b]){
              //  printf("%d %d\n",b,it);
                s.insert(it);
            }
        }
    }
    printf("%lld\n",*s.rbegin());
    while(q--){
        int p,x;
        scanf("%d %d",&p,&x);
        p--;
        for(auto &it:m){
            int loc=p%it.x;
            s.erase(s.find(it.y[loc]));
            it.y[loc]-=a[p]*1ll*it.x;
            //printf("%d",it.y[loc]);
         //   a[p]=x;
            it.y[loc]+=x*1ll*it.x;
           // printf("%d\n",it.y[loc]);
            s.insert(it.y[loc]);
        }
        a[p] =x;       
    printf("%lld\n",*s.rbegin());
    }
}
int main(){
    fill(isprime,isprime+200005,1);
    for(int i = 2;i<=200000;i++){
        if(isprime[i]){
            for(int j = i*2;j<=200000;j+=i)isprime[j]=0;
        }
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}

/*
*/