#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
   /* vector<int> v;
    set<int> s;
    for(int i = 1;i<500;i++){
        if(s.find(i)==s.end())
        for(int j=i+1;j<500;j++){
            if(s.find(j)==s.end()&&s.find(i^j)==s.end()&&(i^j)){
                v.pb(i);
                v.pb(j);
                v.pb(i^j);
                s.insert(i);
                s.insert(j);
                s.insert(i^j);
                break;
            }
        }
    }*/
    while(t--){
        LL n;
        scanf("%lld",&n);
      //  LL cc=v[n-1];
     //   LL now=n;
        LL st=1;
        while((st<<2)<=n){
            st<<=2;
        }
        n-=(st-1);
        LL num=(n-1)/3;
       // printf("%lld %lld\n",n,st);
        if(n%3==1){
            printf("%lld\n",st+num);
           // assert(st+num==cc);
        }
        else{
            vector<int> t;
            LL tmp=st+num;
            while(tmp){
                if(tmp%4==0)t.pb(0);
                if(tmp%4==1)t.pb(2);
                if(tmp%4==2)t.pb(3);
                if(tmp%4==3)t.pb(1);
                tmp/=4;
            }
            reverse(t.begin(),t.end());
            LL ans=0;
            for(auto it:t)ans=(ans<<2)+it;
            if(n%3==2){
                printf("%lld\n",ans);
           //     assert(ans==cc);
            }
            else{
                printf("%lld\n",(st+num)^ans);
             //   assert(((st+num)^ans)==cc);
            }
        }
    }

   /* for(auto it:v){
        bitset<7> b(it);
      //  printf("%d ",it);
       // cout<<b<<endl;
    }*/
  /*  for(int i = 0;i<v.size();i+=3){
        vector<int> t;
        int tmp=v[i];
        while(tmp){
            if(tmp%4==0)t.pb(0);
            if(tmp%4==1)t.pb(2);
            if(tmp%4==2)t.pb(3);
            if(tmp%4==3)t.pb(1);
            tmp/=4;
        }
        reverse(t.begin(),t.end());
        int sum=0;
        for(auto it:t)sum=(sum<<2)+it;
        assert(sum==v[i+1]);
    }*/
}
/*
00 00
01 10
10 11
11 01

*/