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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    set<int> s;
    int gcd=__gcd(a-1,b-1);
    for(int i = 1;i*i<=gcd;i++){
        if(gcd%i==0){
            s.insert(gcd/i);
            s.insert(i);
        }
    }
    gcd=__gcd(a-2,b);
    for(int i = 1;i*i<=gcd;i++){
        if(gcd%i==0){
            s.insert(gcd/i);
            s.insert(i);
        }
    }
    gcd=__gcd(a,b-2);
    for(int i = 1;i*i<=gcd;i++){
        if(gcd%i==0){
            s.insert(gcd/i);
            s.insert(i);
        }
    }
    gcd=__gcd(__gcd(a,b-1),a-2);
    for(int i = 1;i*i<=gcd;i++){
        if(gcd%i==0){
            s.insert(gcd/i);
            s.insert(i);
        }
    }
     gcd=__gcd(__gcd(a-1,b-2),b);
    for(int i = 1;i*i<=gcd;i++){
        if(gcd%i==0){
            s.insert(gcd/i);
            s.insert(i);
        }
    }
    printf("%d\n",s.size());
    for(auto it:s)printf("%d ",it);
    printf("\n");
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/