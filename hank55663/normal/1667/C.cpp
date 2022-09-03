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
    int n;
    scanf("%d",&n);
    if(n==1||n==2){
        printf("1\n1 1\n");
    }
    else{
        vector<pii> v;
        int Max=0;
        for(int i = 0;i<n;i++){
            if((n-i)*2-1<=v.size())break;
            v.pb(mp(i,i));
            if(i%2==0)Max=i;
        }
        for(int i = 1;i<=Max/2;i++)v[i].y=i*2;
        int val=-Max/2;
        for(int i = Max/2+1;i<=Max;i++)v[i].y+=val,val++;
        printf("%d\n",v.size());
        for(auto it:v){
            printf("%d %d\n",it.x+1,it.y+1);
        }
    }
}
int main(){
    int t=1;0000;
  //  scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/