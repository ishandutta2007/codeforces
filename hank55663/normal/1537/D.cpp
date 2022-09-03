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
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    if(n%2==1){
        printf("Bob\n");
    }
    else{
        int cnt=0;
        while(n%2==0){
            cnt++;
            n>>=1;
        }
        if(n!=1)printf("Alice\n");
        else{
            if(cnt%2==0)printf("Alice\n");
            else printf("Bob\n");
        }
    }
}
int main(){
    int t=1;//00;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/