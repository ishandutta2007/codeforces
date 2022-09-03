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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
bool solve(){
    pii p[100005];
    int n;
    scanf("%d",&n);
    map<LL,double> m;
    m[0]=0;
    for(int i=  0;i<n;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
      //  p[i]=mp(x,y);
        LL val=x*x*y;
        
        double add =val*pi;
        //printf("%lld %.12f\n",val,add);
        {
            auto it=prev(m.lower_bound(val));
            m[val]=max(m[val],add+it->y);
        }
        {
            auto it=next(m.lower_bound(val));
            while(it!=m.end()){
                if(it->y<=m[val]){
                    auto it2=next(it);
                    m.erase(it);
                    it=it2;
                }
                else{
                    break;
                }
            }
        }
       // for(auto it:m){
         //   printf("%d %.12f\n",it.x,it.y);
       // }
    }
    printf("%.12f\n",m.rbegin()->y);
  
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();//solve();
}
/*

4 7 2 1 7 4 3 1 7 2
*/