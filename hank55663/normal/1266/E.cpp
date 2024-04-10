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
int a[200005];
vector<pii> v[200005];
map<pii,int> m;
map<pii,int> now;
int main(){
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    int q;
    scanf("%d",&q);
    while(q--){
        int aa,b,c;
        scanf("%d %d %d",&aa,&b,&c);
        if(now.find(mp(aa,b))!=now.end()){
            a[now[mp(aa,b)]]++;
            if(a[now[mp(aa,b)]]>0)sum++;
            now.erase(mp(aa,b));
        }
        if(c){
            now[mp(aa,b)]=c;
            a[c]--;
            if(a[c]>=0)sum--;
        }
        printf("%lld\n",sum);
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