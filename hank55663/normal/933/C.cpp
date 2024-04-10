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
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define ld long double
pdd operator+(cpdd &p,cpdd &q){
    return {p.x+q.x,p.y+q.y};
}
pdd operator-(cpdd &p,cpdd &q){
    return {p.x-q.x,p.y-q.y};
}
ld operator*(cpdd &p,cpdd &q){
    return p.x*q.x+p.y*q.y;
}
pdd operator*(double f,cpdd &p){
    return {p.x*f,p.y*f};
}
vector<pdd> interCircle(pdd o1, double r1, pdd o2,double r2) {
    ld d2 = (o1 - o2) * (o1 - o2);
    ld d = sqrt(d2);
   // cout<<d2<<" "<<d;
    if (d > r1+r2||d<abs(r1-r2)) return {};
    pdd u = 0.5*(o1+o2) + ((r2*r2-r1*r1)/(2*d2))*(o1-o2);
    double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) *
    (-r1+r2+d));
    if(abs(A)<=1e-8){
        return {u};
    }
    pdd v = A / (2*d2) * pdd(o1.y-o2.y, -o1.x+o2.x);
    return {u+v, u-v};
}
double abs(cpdd &p){return hypot(p.x,p.y);}
int main(){
    int n;
    scanf("%d",&n);
    pair<pdd,double> p[3];
    for(int i = 0;i<n;i++){
        int x,y,r;
        scanf("%d %d %d",&x,&y,&r);
        p[i]=mp(mp(x,y),r);
    }
    if(n==1){
        printf("2\n");
    }
    else if(n==2){
        if(interCircle(p[0].x,p[0].y,p[1].x,p[1].y).size()==2){
            printf("4\n");
        }
        else{
            printf("3\n");
        }
    }
    else{
        vector<pdd> vv;
        int e=0;
        int add = 1;
        for(int i =0;i<n;i++){
            vector<pdd> v;
            for(int j=0;j<n;j++){
                if(i!=j){
                    for(auto it:interCircle(p[i].x,p[i].y,p[j].x,p[j].y)){
                        v.pb(it);
                        vv.pb(it);
                   //     printf("%f %f\n",it.x,it.y);
                    }
                }
            }
            e+=v.size();
            for(int j=0;j<v.size();j++){
                for(int k=j+1;k<v.size();k++){
                    // printf("?\n");
                    if(abs(v[k]-v[j])<1e-6)e--;
                }
            }
            if(v.empty()){
                add++;
                vv.pb(mp(100+i,100+i));
                e++;
            }
         //   printf("%d?\n",e);
        }
      //  printf("%d\n",e);
       // printf("?\n");
        vector<pdd> tmp;
        for(int j=0;j<vv.size();j++){
            int ok=1;
            for(int k=j+1;k<vv.size();k++){
                if(abs(vv[j]-vv[k])<1e-6)ok=0;
            }
            if(ok)tmp.pb(vv[j]);
        }
        if(add==4)add--;
        printf("%d\n",e-tmp.size()+add+1);
    }
}