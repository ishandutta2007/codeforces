
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int Transform(char c){
    if(c=='A')return 0;
    if(c=='T')return 9;
    if(c=='J')return 10;
    if(c=='Q')return 11;
    if(c=='K')return 12;
    return c-'1';
}
bool cmp(const pii &a,const pii &b){
    return a.y<b.y;
}
int main(){
    pii p[3];
    int Minx=1e9,Maxx=-1,Miny=1e9,Maxy=0;
    for(int i=0;i<3;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        Minx=min(Minx,x);
        Maxx=max(Maxx,x);
        Miny=min(Miny,y);
        Maxy=max(Maxy,y);
    }
    printf("%d\n",Maxx-Minx+Maxy-Miny+1);
    sort(p,p+3);
    set<pii> s;
    for(int i=p[0].x;i<=p[1].x;i++){
        s.insert(mp(i,p[0].y));
    }
    for(int i=p[2].x;i>=p[1].x;i--){
        s.insert(mp(i,p[2].y));
    }
    int xx=p[1].x;
    sort(p,p+3,cmp);
    for(int i=p[0].y;i<=p[2].y;i++){
        s.insert(mp(xx,i));
    }
    for(auto it:s)
    printf("%d %d\n",it.x,it.y);
    return 0;
}