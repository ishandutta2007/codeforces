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
void solve(int T){
    int n;
    scanf("%d",&n);
    int a[100005];
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>=2)v.pb(mp(a[i]-a[i-1],i));
    }
    v.pb(mp(0,1));
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int now=0;
    for(int i = 1;i<=n;i++){
        while(now!=v.size()-1&&v[now].x>=0)now++;
        printf("%d ",v[now].y);
        v[now].x+=i;
    }
    printf("\n");

}

int main(){
    int t=1;
     scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*

*/