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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int f[1005];
int Size[1005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,d;
    scanf("%d %d",&n,&d);
    multiset<int> s;
    for(int i = 1;i<=n;i++)f[i]=i,Size[i]=1,s.insert(-1);
    int tot=1;
    for(int i = 0;i<d;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a=Find(x),b=Find(y);
        if(a==b){
            tot++;
        }
        else{
            f[a]=b;
            s.erase(s.find(-Size[b]));
            s.erase(s.find(-Size[a]));
            Size[b]+=Size[a];
            s.insert(-Size[b]);
        }
        int sum=0;
        int cnt=0;
        for(auto it:s){
            sum-=it;
            cnt++;
            if(cnt==tot)break;
        }
       // for(auto it:s)printf("%d ",it);
       // printf("\n");
        printf("%d\n",sum-1);
    }
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/