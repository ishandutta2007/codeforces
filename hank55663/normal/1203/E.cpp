#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    //int q;
   // scanf("%d",&q);
   // while(q--){
       int n;
       scanf("%d",&n);
       multiset<int> s;
       for(int i = 0;i<n;i++){
           int x;
           scanf("%d",&x);
           s.insert(x);
       }
       int ans=0;
       for(int i = 1;i<=150001;i++){
           if(s.find(i-1)!=s.end()){
               ans++;
               s.erase(s.find(i-1));
           }
           else if(s.find(i)!=s.end()){
               ans++;
               s.erase(s.find(i));
           }
           else if(s.find(i+1)!=s.end()){
               ans++;
               s.erase(s.find(i+1));
           }
       }
       printf("%d\n",ans);
   // }
    return 0;
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */