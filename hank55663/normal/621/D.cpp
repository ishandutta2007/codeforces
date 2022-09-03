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
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
string ans[12]={"x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y","z^y^x","(z^x)^y","(z^y)^x"};
bool solve(){
    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    if(x<5&&y<5&&z<5){
        long double a[12]={powl(y,z)*logl(x),powl(z,y)*logl(x),y*z*logl(x),z*y*logl(x),
                           powl(x,z)*logl(y),powl(z,x)*logl(y),x*z*logl(y),z*x*logl(y),
                           powl(x,y)*logl(z),powl(y,x)*logl(z),x*y*logl(z),y*x*logl(z)};
        long double Max=a[0];
        int idx=0;
       // cout<<a[0]<<endl;
        //cout<<logl(logl(x))<<endl;
        for(int i = 1;i<12;i++){
            if(a[i]>Max){
                Max=a[i];
                idx=i;
            }
        }
        printf("%s\n",ans[idx].c_str());
    }
    else{
        long double a[12]={z*logl(y)+logl(logl(x)),y*logl(z)+logl(logl(x)),logl(y*z*logl(x)),logl(z*y*logl(x)),
                    z*logl(x)+logl(logl(y)),x*logl(z)+logl(logl(y)),logl(x*z*logl(y)),logl(z*x*logl(y)),
                    y*logl(x)+logl(logl(z)),x*logl(y)+logl(logl(z)),logl(x*y*logl(z)),logl(y*x*logl(z))};
        if(logl(x)<1e-8)a[0]=a[1]=a[2]=a[3]=-1e9;
        if(logl(y)<1e-8)a[4]=a[5]=a[6]=a[7]=-1e9;
        if(logl(z)<1e-8)a[8]=a[9]=a[10]=a[11]=-1e9;
        long double Max=a[0];
        int idx=0;
       // cout<<a[0]<<endl;
        //cout<<logl(logl(x))<<endl;
        for(int i = 1;i<12;i++){
            if(a[i]>Max){
                Max=a[i];
                idx=i;
            }
        }
        printf("%s\n",ans[idx].c_str());
    }
    return true;
}
int main(){
    int t=1;00000;
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/