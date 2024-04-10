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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 200005
vector<int> v[200005];
int num[200005];
int main(){
    int n;
    scanf("%d",&n);
    pii p[100005];
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i*2-1);
    }
    sort(p+1,p+n+1);
    reverse(p+1,p+n+1);
    int now=n;
    for(int i = 1;i<=n;i++){
        num[i]=p[i].y;
    }
    for(int i = 1;i<=n;i++){
        int target=i+p[i].x-1;
        if(target==now){
            num[now+1]=p[i].y+1;
            now++;
        }
        else{
            v[target].pb(p[i].y+1);
        }
    }
    for(int i = 1;i<now;i++){
        printf("%d %d\n",num[i],num[i+1]);
        for(auto it:v[i]){
            printf("%d %d\n",num[i],it);
        }
    }
    
}