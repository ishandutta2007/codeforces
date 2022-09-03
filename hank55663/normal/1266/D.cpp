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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
LL coin[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ;i<m;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        coin[x]-=c;
        coin[y]+=c;
    }
    vector<int> pos,neg;
    for(int i = 1;i<=n;i++){
        if(coin[i]>0)pos.pb(i);
        else if(coin[i]<0)neg.pb(i);
    }
    vector<pair<pii,LL> > v;
    while(pos.size()&&neg.size()){
        LL x=min(coin[pos.back()],-coin[neg.back()]);
        v.pb(mp(mp(pos.back(),neg.back()),x));
        coin[pos.back()]-=x;
        coin[neg.back()]+=x;
        if(coin[pos.back()]==0)pos.pop_back();
        if(coin[neg.back()]==0)neg.pop_back();
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %lld\n",it.x.y,it.x.x,it.y);
    }
}
/*
510510

255255
170170
102102
72930
46410
39270
30030

5 3
3 -1 
4 2 
1 1 
5 3 
2 2 
4 1 
3 2 
5 3 

*/