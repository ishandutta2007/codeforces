#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
struct edge{
    pdd p1;
    pdd p2;
    edge(pdd _p1,pdd _p2):p1(_p1),p2(_p2){}
};
double x;
bool operator<(const edge &p,const edge &q){
    if(p.p1==q.p1&&p.p2==q.p2)return false;
    double pp=((p.p2.x-x)*(p.p1.y)+(x-p.p1.x)*(p.p2.y))/(p.p2.x-p.p1.x);
    double qq=((q.p2.x-x)*(q.p1.y)+(x-q.p1.x)*(q.p2.y))/(q.p2.x-q.p1.x);
    return pp<qq;
}
#define cpdd const pdd
pdd operator+(cpdd &p,cpdd &q){
    return {p.x+q.x,p.y+q.y};
}
pdd operator-(cpdd &p,cpdd &q){
    return {p.x-q.x,p.y-q.y};
}
double cross(cpdd &p,cpdd &q){
    return p.x*q.y-p.y*q.x;
}
double cross(cpdd &p,cpdd &q,cpdd &o){
    return cross(p-o,q-o);
}
pdd operator*(double f,cpdd &p){
    return {p.x*f,p.y*f};
}
bool interPnt(edge p,edge q)
{
    int ok1=0,ok2=0;
    pdd p1=p.p1,p2=p.p2,q1=q.p1,q2=q.p2;
    double f1=cross(p1,p2,q1),f2=cross(p1,p2,q2);
    if(abs(f1)<EPS||abs(f2)<EPS)ok1=1;
    if(f1*f2<0)ok1=1;
    f1=cross(q1,q2,p1),f2=cross(q1,q2,p2);
     if(abs(f1)<EPS||abs(f2)<EPS)ok2=1;
    if(f1*f2<0)ok2=1;
    return ok1&&ok2;
}
bool check(vector<edge> E){
    vector<pair<double,int> > v;
    for(int i = 0;i<E.size();i++){
        v.pb(mp(E[i].p1.x,i));
        v.pb(mp(E[i].p2.x,i));
    }
    sort(v.begin(),v.end());
    set<pair<edge,int> > s;
    int in[25005];
    MEM(in);

    for(auto p:v){
        x=p.x;
        if(!in[p.y]){
            in[p.y]=1;
            s.insert(mp(E[p.y],p.y));
            auto it=s.find(mp(E[p.y],p.y));
            assert(it!=s.end());
            if(it!=s.begin()){
                edge e1=it->x,e2=prev(it)->x;
                if(interPnt(e1,e2))return true;
            }
            if(next(it)!=s.end()){
                edge e1=it->x,e2=next(it)->x;
                if(interPnt(e1,e2))return true;
            }
        }
        else{       
            in[p.y]=0;
            auto it=s.find(mp(E[p.y],p.y));
            if(it!=s.begin()&&next(it)!=s.end()){
                edge e1=next(it)->x,e2=prev(it)->x;
                if(interPnt(e1,e2))return true;
            }
            s.erase(mp(E[p.y],p.y));

        }
    }
   // printf("\n");
    return false;
}
double abs(int x,int y){
    return sqrt(x*x+y*y);
}
int main(){
    int n;
    scanf("%d",&n);
    int x[25005],y[25005],dx[25005],dy[25005],s[25005];
    for(int i = 0;i<n;i++){
        scanf("%d %d %d %d %d",&x[i],&y[i],&dx[i],&dy[i],&s[i]);
    }
    double Max=1000000000000,Min=0;
    int ok=0;
    for(int t = 0;t<100;t++){
        double mid=(Max+Min)/2;
        vector<edge> v;
        for(int i=0;i<n;i++){
            pdd p1=mp(x[i],y[i]);
            double ddx=dx[i]/abs(dx[i],dy[i]);
            double ddy=dy[i]/abs(dx[i],dy[i]);
            //printf("%lf %lf\n",ddx,ddy);
            pdd p2=mp(x[i]+ddx*mid*s[i],y[i]+ddy*mid*s[i]);
            if(p2.x<p1.x)swap(p2,p1);
            v.pb({p1,p2});
         //   printf("%lf %lf %lf %lf %lf\n",mid,p1.x,p1.y,p2.x,p2.y);
        }
        if(check(v)){
            Max=mid;
            ok=1;
        }
        else{
            Min=mid;
        }
    }
    if(!ok){
        printf("No show :(\n");
    }
    else{
        printf("%.12f\n",Max);
    }
}
/*
2 11 14
9 3


000111222
001112220
*/