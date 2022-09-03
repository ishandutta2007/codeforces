#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    multiset<pii> pq;
    multiset<pii> pool;
    pool.insert(mp(0,0));
    int cnt=0;
    int incnt=0;
    LL sum=0;
    LL pqsum=0;
    for(int i = 0;i<n;i++){
        int tp,d;
        scanf("%d %d",&tp,&d);
        if(d>0){
            if(tp==0){
                pool.insert(mp(d,tp));
                sum+=d;
            }
            else{
                cnt++;
                pool.insert(mp(d,tp));
                sum+=d;
            }
        }
        else{
            d=-d;
            if(tp==1)cnt--;
            if(pool.find(mp(d,tp))!=pool.end()){
                pool.erase(pool.find(mp(d,tp)));
                sum-=d;
            }
            else{
                pq.erase(pq.find(mp(d,tp)));
                sum-=d;
                pqsum-=d;
                if(tp)incnt--;
            }
        }
        
        while(pool.size()&&pq.size()&&pool.rbegin()->x>pq.begin()->x){
            pq.insert(*pool.rbegin());
            incnt+=pool.rbegin()->y;
            pqsum+=pool.rbegin()->x;
            pool.erase(pool.find(*pool.rbegin()));
        }
        while(pq.size()>cnt){
            pool.insert(*pq.begin());
            incnt-=pq.begin()->y;
            pqsum-=pq.begin()->x;
            pq.erase(pq.begin());
        }
        while(pq.size()<cnt){
            pq.insert(*pool.rbegin());
            incnt+=pool.rbegin()->y;
            pqsum+=pool.rbegin()->x;
            pool.erase(pool.find(*pool.rbegin()));
        }
      //  printf("%d %d %d %d\n",sum,pqsum,incnt,cnt);
        //printf("%d %d %d\n",cnt,pqsum);
        if(incnt==cnt&&cnt){
            printf("%lld\n",sum+pqsum-pq.begin()->x+pool.rbegin()->x);
        }
        else{
            printf("%lld\n",sum+pqsum);
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/