#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1);
int sig(double r){return (r<-EPS)?-1:(r>+EPS)?+1:0;}
struct Pt{
    double x,y;
    Pt(){}
    Pt(double x,double y):x(x),y(y){};
    Pt operator+(const Pt &a)const{return Pt(x+a.x,y+a.y);}
    Pt operator-(const Pt &a)const{return Pt(x-a.x,y-a.y);}
    Pt operator*(const Pt &a)const{return Pt(x*a.x-y*a.y,x*a.y+y*a.x);}
    Pt operator-()const{return Pt(-x,-y);}
    Pt operator*(const double &k)const{return Pt(x*k,y*k);}
    Pt operator/(const double &k)const{return Pt(x/k,y/k);}
    double abs()const{return sqrt(x*x+y*y);}
    double abs2()const{return x*x+y*y;}
    double arg()const{return atan2(y,x);}
    double dot(const Pt&a)const{return x*a.x+y*a.y;}
    double det(const Pt&a)const{return x*a.y-y*a.x;}
};
inline bool operator<(const Pt&a,const Pt&b){
    if(sig(a.x-b.x))return a.x<b.x;
    return a.y<b.y;
}
double tri(const Pt&a,const Pt&b,const Pt&c){return (b-a).det(c-a);}
 
int iSP(Pt a,Pt b,Pt c){
    int s=sig((b-a).det(c-a));
    if(s)return s;
    if(sig((b-a).dot(c-a))<0)return -2;
    if(sig((a-b).dot(c-b))<0)return +2;
    return 0;
}
int iLL(Pt a,Pt b,Pt c,Pt d){
    if(sig((b-a).det(d-c)))return 1;
    if(sig((b-a).det(c-a)))return 0;
    return -1;
}
bool iSS(Pt a,Pt b,Pt c,Pt d){
    return (iSP(a,b,c)*iSP(a,b,d)<=0&&iSP(c,d,a)*iSP(c,d,b)<=0);
}
bool iSSS(Pt a,Pt b,Pt c,Pt d){
    return (sig(tri(a, b, c)) * sig(tri(a, b, d)) < 0 && sig(tri(c, d, a)) * sig(tri(c, d, b)) < 0);
}
Pt pLL(Pt a,Pt b,Pt c,Pt d){
    b=b-a;d=d-c;return a+b*(c-a).det(d)/b.det(d);
}
int sGP(int n,Pt p[],Pt a){
    int side=-1,i;
    p[n]=p[0];
    for(i=0;i<n;i++){
        Pt p0=p[i]-a,p1=p[i+1]-a;
        if(sig(p0.det(p1))==0&&sig(p0.dot(p1))<=0)return 0;
        if(p0.y>p1.y)swap(p0,p1);
        if(sig(p0.y)<=0&&0<sig(p1.y)&&sig(p0.det(p1))>0)side=-side;
    }
    return side;
}
double x[210];
double y[210];
int ok[210][210];
Pt poly[210];
int dp[210][210];
int mod=1000000007;
int calc(int a,int b){
    if(~dp[a][b])return dp[a][b];
    if(a+2==b){
        if(ok[a][b])return dp[a][b]=1;
        else return dp[a][b]=0;
    }
    if(a+1==b){
        return dp[a][b]=1;
    }
    int ret=0;
    for(int i=a+1;i<b;i++){
        if(ok[a][i]&&ok[i][b])ret=(ret+(long long)calc(a,i)*calc(i,b)%mod)%mod;
    }
    return dp[a][b]=ret;
}
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%lf%lf",x+i,y+i);
        poly[i]=Pt(x[i],y[i]);
    }
    for(int i=0;i<210;i++)
        for(int j=0;j<210;j++)
            dp[i][j]=-1;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i==j)continue;
            bool OK=true;
            double mx=(x[i]+x[j])/2;
            double my=(y[i]+y[j])/2;
            if(sGP(a,poly,Pt(mx,my))==-1)OK=false;
            for(int k=0;k<a;k++){
                if(iLL(poly[k],poly[(k+1)%a],poly[i],poly[j])==-1){
                    if((!(k==i&&(k+1)%a==j))&&(!(k==j&&(k+1)%a==i))&&iSP(poly[i],poly[j],poly[k])==0&&iSP(poly[i],poly[j],poly[(k+1)%a])==0){
            //      if(i+1==j)printf("%d %d %d\n",i,j,k);
                        OK=false;
                    }
                }
                else if(iSS(poly[k],poly[(k+1)%a],poly[i],poly[j])){

                    Pt p=pLL(poly[k],poly[(k+1)%a],poly[i],poly[j]);
                    if((p-poly[i]).abs()>EPS&&(p-poly[j]).abs()>EPS){
                        
                        OK=false;
                    }
                }
            }
            if(OK)ok[i][j]=1;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
        //  printf("%d ",ok[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",calc(0,a-1));
}