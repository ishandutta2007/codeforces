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
//#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define Line pair<pii,pii> 
typedef long long LL;
pll operator +(const pll &p,const pll &q){
    return {p.x+q.x,p.y+q.y};
}
pll operator -(const pll &p){
    return {-p.x,-p.y};
}
pll operator -(const pll &p,const pll &q){
    return p+(-q);
}
pll operator *(LL l,const pll &p){
    return {l*p.x,l*p.y};
}
LL operator *(const pll &p,const pll &q){
    return p.x*q.x+p.y*q.y;
}

LL cross(pll p,pll q){
    return p.x*q.y-p.y*q.x;
}
LL cross(pll p,pll q,pll o){
    return cross(p-o,q-o);
}
pll operator *(const pll &p,LL l){
    return l*p;
}
pll interPnt(pll p1,pll p2,pll q1,pll q2,bool &res){
    LL f1 = cross(p2,q1,p1);
    LL f2 = -cross(p2,q2,p1);
    LL f = f1+f2;
    if( f==0){
        res = false;
        return {};
    }
    pll ret=f2*q1+f1*q2;
    //printf("? %lld %lld %lld\n",ret.x,ret.y,f);
    if(ret.x%f!=0||ret.y%f!=0){
        res=false;
        return {};
    }
    res=true;
    //printf("!\n");
    ret.x/=f;
    ret.y/=f;
    return ret;
}
bool inLine(pll p,pll p1, pll p2){
    LL Minx=min(p1.x,p2.x);
    LL Maxx=max(p1.x,p2.x);
    LL Miny=min(p1.y,p2.y);
    LL Maxy=max(p1.y,p2.y);
    if(p.x>=Minx&&p.x<=Maxx&&p.y>=Miny&&p.y<=Maxy)
    return true;
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    Line l[1005];
    LL ans=0;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        l[i]=mp(mp(x1,y1),mp(x2,y2));
        ans+=__gcd(abs(x2-x1),abs(y2-y1))+1;
    }
    set<pll> s[1005];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool res;
            pll p=interPnt(l[i].x,l[i].y,l[j].x,l[j].y,res);
            if(res){
                if(inLine(p,l[i].x,l[i].y)&&inLine(p,l[j].x,l[j].y)){
                    if(s[j].find(p)!=s[j].end())
                    continue;
                    s[j].insert(p);
                    ans--;
                }
            }
        }
    }
    printf("%lld\n",ans);
}