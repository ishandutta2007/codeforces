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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int a[50005],b[50005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    set<int> s;
    int ok=1;
    int Min=0;
    for(int i = 0;i<n;i++){
        if(b[i]){
            s.insert(a[i]-b[i]);
            if(a[i]<b[i])ok=0;
            
        }
        else{
            Min=max(Min,a[i]);
        }
    }
    if(s.size()<=1&&ok){
        if(s.size()&&*s.begin()<Min){
            printf("No\n");
        }
        else
        printf("Yes\n");
    }
    else printf("No\n");
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}