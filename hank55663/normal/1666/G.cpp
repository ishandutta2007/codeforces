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
#define double long double
using namespace std;
double dis(double x1,double y1,double z1,double x2,double y2,double z2){
    return sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
}
vector<pair<int,vector<double> > > tri[1000005];
vector<int> v[100005];
vector<int> node[1000005];
vector<pii> query[1000005];
int f[100005];
double s2[100005],s[100005],c[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
double ans[100005];
int has[100005];
LL x[100005],y[100005],z[100005];
void go(){
    for(LL i = 1000000;i>=0;i--){
            
        for(auto it:query[i]){
            if(z[it.x]<=i)ans[it.y]=-1,has[it.y]=0;
            else{
                int x=Find(it.x);
                ans[it.y]=s2[x]*i*i+s[x]*i+c[x];
              //  printf("%d %.12f %.12f %.12f\n",i,s2[x],s[x],c[x]);
                has[it.y]=1;
            }
        }
        for(auto it:node[i]){
            for(auto x:v[it]){
                int a=Find(it),b=Find(x);
                if(a!=b){
                f[a]=b;
                s2[b]+=s2[a];
                s[b]+=s[a];
                c[b]+=c[a];
                }
            }
        }
        for(auto p:tri[i]){
            int a=Find(p.x);
            s2[a]+=p.y[0];
            s[a]+=p.y[1];
            c[a]+=p.y[2];
          //  printf("%.12f %.12f %.12f\n",p.y[0],p.y[1],p.y[2]);
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
        node[z[i]].pb(i);
    }
    int m;
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        int a[3];
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        for(int x=0;x<3;x++){
            for(int y=x+1;y<3;y++){
                if(z[a[x]]>z[a[y]])swap(a[x],a[y]);
            }
        }
        for(int x=0;x<3;x++){
            for(int y=x+1;y<3;y++){
                v[a[x]].pb(a[y]);
            }
        }
        LL z1=z[a[1]]-z[a[0]],z2=z[a[2]]-z[a[1]];
        if(z1+z2==0){
            LL x1=x[a[2]]-x[a[0]],x2=x[a[1]]-x[a[0]];
            LL y1=y[a[2]]-y[a[0]],y2=y[a[1]]-y[a[0]];
         
            tri[z[a[0]]].pb(mp(a[2],vector<double>{0,0,   abs(x1*y2-x2*y1)*0.5}));
         //   printf("%d %d %d %.12f\n",a[0],a[1],a[2],  abs(x1*y2-x2*y1)*0.5);
            continue;
        }
        double xx=(x[a[0]]*z2+x[a[2]]*z1)*1.0/(z1+z2),yy=(y[a[0]]*z2+y[a[2]]*z1)*1.0/(z1+z2);
        double face=0;
        double addc=0,adds=0,adds2=0;
        //upper
        if(z2)
        {
            double aa=dis(x[a[2]],y[a[2]],z[a[2]],x[a[1]],y[a[1]],z[a[1]]);
            double bb=dis(x[a[2]],y[a[2]],z[a[2]],xx,yy,z[a[1]]);
            double cc=dis(xx,yy,z[a[1]],x[a[1]],y[a[1]],z[a[1]]);
            double tot=(aa+bb+cc)/2;
            double s=sqrt(tot*(tot-aa)*(tot-bb)*(tot-cc));
            face+=s;
            //z[a[2]],a[2],s/(z[a[2]]-z[a[1]])*(z[a[2]]-h); 
            double mon=1.0/(z[a[2]]-z[a[1]]);
            mon=mon*mon*s;
          //  (z[a[2]]*z[a[2]]-2*z[a[2]]*h+h*h)
            adds2=mon;
            adds=-2*z[a[2]]*mon;
            addc=z[a[2]]*z[a[2]]*mon;
            tri[z[a[2]]].pb(mp(a[2],vector<double>{adds2,adds,addc}));
         //   printf("%.12f ",addc);
        }
        //down
        if(z1)
        {
            double aa=dis(x[a[0]],y[a[0]],z[a[0]],x[a[1]],y[a[1]],z[a[1]]);
            double bb=dis(x[a[0]],y[a[0]],z[a[0]],xx,yy,z[a[1]]);
            double cc=dis(xx,yy,z[a[1]],x[a[1]],y[a[1]],z[a[1]]);
            double tot=(aa+bb+cc)/2;
            double s=sqrt(tot*(tot-aa)*(tot-bb)*(tot-cc));
            face+=s;
            //s/(z[a[1]]-z[a[0]])*(h-z[a[0]])

            double mon=1.0/(z[a[1]]-z[a[0]]);
            mon=mon*mon*s;
            z[a[1]],a[2],-adds2+mon,-adds-2*z[a[0]]*mon,-addc+face+z[a[0]]*z[a[0]]*mon;
            tri[z[a[1]]].pb(mp(a[2],vector<double>{-adds2-mon,-adds+2*z[a[0]]*mon,-addc+face-z[a[0]]*z[a[0]]*mon}));
         //   printf("%.12f ",-addc+face-z[a[0]]*z[a[0]]*mon);
            adds2=-mon;
            adds=2*z[a[0]]*mon;
            addc=-z[a[0]]*z[a[0]]*mon;
        }
        else{
            tri[z[a[1]]].pb(mp(a[2],vector<double>{0,0,face}));
        }
        tri[z[a[0]]].pb(mp(a[2],vector<double>{-adds2,-adds,-addc}));
      //  printf("%.12f\n",-addc);
     //   printf("%.12f\n",-adds2);
       // printf("%d %d %d %.12f\n",a[0],a[1],a[2],face);
      //  printf("%d %d %d\n",z[a[0]],z[a[1]],z[a[2]]);
    }
    for(int i = 1;i<=n;i++)f[i]=i,s2[i]=s[i]=c[i]=0;
    int q;
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        int h,p;
        scanf("%d %d",&h,&p);
        query[h].pb(mp(p,i));
    }
    go();
    for(int i = 1;i<=q;i++){
        if(has[i])printf("%.12Lf\n",ans[i]);
        else printf("-1\n");
    }
}
int main(){
    int t=1;00000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/