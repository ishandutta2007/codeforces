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
const int mod=1e9+7;
void solve(){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    if(a>b)swap(a,b);
    if(k==1){
        if(b%a==0){
            if(a==b)printf("NO\n");
            else printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
        int Max=0;
        for(int i = 2;i*i<=a;i++){
            while(a%i==0){
                Max++;
                a/=i;
            }
        }
        if(a!=1)Max++;
        for(int i = 2;i*i<=b;i++){
            while(b%i==0){
                Max++;
                b/=i;
            }
        }
        if(b!=1)Max++;
        if(k<=Max){
            printf("YEs\n");
        }
        else{
            printf("NO\n");
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/