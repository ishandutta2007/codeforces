#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    vector<int> pos,neg;
    int zero=0;
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a>0)pos.pb(a);
        if(a<0)neg.pb(a);
        if(a==0)zero++;
    }
    if(pos.size()){
        sort(pos.begin(),pos.end());
        reverse(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        if(pos.size()+neg.size()<5){
            printf("0\n");
        }
        else if(pos.size()+neg.size()==5){
            LL ans=1;
            for(auto it:pos)ans*=it;
            for(auto it:neg)ans*=it;
            if(ans>0)printf("%lld\n",ans);
            else printf("%lld\n",zero?0ll:ans);
        }
        else{
            LL ans=pos[0];
            int l=1,r=0;
            for(int i = 0;i<2;i++){
                LL p=-1,n=-1;
                if(pos.size()>l+1)p=pos[l]*pos[l+1];
                if(neg.size()>r+1)n=neg[r]*neg[r+1];
                if(p>n)ans*=p,l+=2;
                else ans*=n,r+=2;
                //printf("%lld %lld\n",p,n);
            }
            printf("%lld\n",ans);
        }
    }
    else{
        if(zero){
            printf("0\n");
        }
        else{
            sort(neg.begin(),neg.end());
            reverse(neg.begin(),neg.end());
            LL ans=1;
            for(int i = 0;i<5;i++)ans*=neg[i];
            printf("%lld\n",ans);
        }
    }
  //  printf("%d\n",ans);
}

int main(){
    int t=1;
    scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/