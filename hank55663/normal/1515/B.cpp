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
#define last Last
#define MAXK 2500
set<int> s;
void solve(){
    int n;
    scanf("%d",&n);
    if(n%2==1){
        printf("NO\n");
    }
    else{
        int x=n/2;
        if(s.find(x)!=s.end()){
            printf("YES\n");
            return;
        }
        if(n%4==0){
        x=n/4;
        if(s.find(x)!=s.end()){
            printf("YES\n");
            return;
        }
        }
        printf("NO\n");
    }
}
int main(){
    for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36

x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/