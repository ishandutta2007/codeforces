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
pdd operator+(const pdd &a,const pdd &b){
    return {a.x+b.x,a.y+b.y};
}
pdd operator-(const pdd &a,const pdd &b){
    return {a.x-b.x,a.y-b.y};
}
double operator*(const pdd &a,const pdd &b){
    return a.x*b.x+a.y*b.y; 
}
pdd operator*(const double &a,const pdd &b){
    return {a*b.x,a*b.y}; 
}
struct Mcc{
    // return pair of center and r^2
    static const int MAXN = 1000100;
    int n;
    pdd p[MAXN],cen;
    double r2;
    void init(int _n, pdd _p[]){
        n = _n;
        memcpy(p,_p,sizeof(pdd)*n);
    }
    double sqr(double a){ return a*a; }
    double abs2(pdd a){ return a*a; }
    pdd center(pdd p0, pdd p1, pdd p2) {
        pdd a = p1-p0;
        pdd b = p2-p0;
        double c1=abs2(a)*0.5;
        double c2=abs2(b)*0.5;
        double d = a.x*b.y-b.x*a.y;
        double x = p0.x + (c1 * b.y - c2 * a.y) / d;
        double y = p0.y + (a.x * c2 - b.x * c1) / d;
        return pdd(x,y);
    }
    pair<pdd,double> solve(){
        random_shuffle(p,p+n);
        r2=0;
        for (int i=0; i<n; i++){
            if (abs2(cen-p[i]) <= r2) continue;
            cen = p[i];
            r2 = 0;
            for (int j=0; j<i; j++){
                if (abs2(cen-p[j]) <= r2) continue;
                cen = 0.5 * (p[i]+p[j]);
                r2 = abs2(cen-p[j]);
                for (int k=0; k<j; k++){
                    if (abs2(cen-p[k]) <= r2) continue;
                    cen = center(p[i],p[j],p[k]);
                    r2 = abs2(cen-p[k]);
                }
            }
        }
        return {cen,r2};
    }
}mcc;
int main(){
    int n;
    scanf("%d",&n);
    pdd p[100005];
    int pos=0,neg=0,zero=0;
    for(int i=0;i<n;i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        if(y>1e-8)
        pos++;
        else if(y<-1e-8)
        neg++;
        else
        zero++;
        if(y<0)
        y=-y;
        p[i]=mp(x,y);
    }
    if(pos&&neg){
        printf("-1\n");
    }
    else if(zero>=2){
        printf("-1\n");
    }
    else{
        long double Max=1e15,Min=0;
        for(int i=1;i<=100;i++){
            long double mid=(Max+Min)/2;
            int ok=1;
            long double l=-1e18,r=1e18;
            for(int j=0;j<n;j++){
                if(p[j].y>2*mid){
                    ok=0;
                }
                else{
                    long double tot=abs(p[j].y-mid);
                    long double Size=sqrt(abs(-2*mid*p[j].y+p[j].y*p[j].y));
                   // cout<<i<<" "<<Size<<endl;
                    l=max(l,p[j].x-Size);
                    r=min(r,p[j].x+Size);
                }
            }
           // cout<<fixed<<setprecision(12)<<ok<<" "<<mid<<" "<<l<<" "<<r<<endl;
            //printf("%d %lf %lf %lf\n",ok,mid,l,r);
            if(l>r)
            ok=0;
            if(ok){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        cout<<fixed<<setprecision(12)<<Max<<endl;
        //printf("%.12lf\n",Max);
    }
    return 0;
}