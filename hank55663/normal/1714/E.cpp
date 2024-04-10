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
//pair<pii,int> from[105];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int ok=1;
    set<int> s;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        while(a[i]%10&&a[i]%10!=2){
            a[i]+=a[i]%10;
           // printf("%d\n",a[i]);
           // getchar();
        }
        if(a[i]%10==2)s.insert(((a[i]/10)&1)+1);
        else s.insert(a[i]);
        //printf("%d ",a[i]);
    }  
    if(s.size()==1)printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/