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
void solve(){
    bitset<200005> b;
    b[0]=1;
    int n;
    scanf("%d",&n);
    int sum=0;
    int a[2005];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        b=b|(b<<x);
        sum+=x;
        a[i]=x;
    }
    if(sum%2!=0||b[sum/2]==0){
        printf("0\n");
    }
    else{
        for(int i = 0;i<20;i++){
            for(int j = 0;j<n;j++){
                if(a[j]&(1<<i)){
                    printf("1\n%d\n",j+1);
                    return;
                }
            }
        }
    }
}
int main(){
    int t=1;00000;
 //   scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/