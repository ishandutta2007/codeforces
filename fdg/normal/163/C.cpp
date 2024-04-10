#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

const double eps=1e-12,eps2=1e-7;
double p[200005];
int w[200005];
double ans[100005];

bool can(int v1,int v2,int l,int pos,double a) {
    double d=1.0*(a-pos)*v1/v2;
    return (a-pos)+d-eps<l;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,l,v1,v2;
    scanf("%d%d%d%d",&n,&l,&v1,&v2);
    int N=n;
    for(int i=0;i<n;++i) {
        scanf("%lf",&p[i]);
        w[i]=1;
    }
    if (p[0]!=0) {
        for(int i=n-1;i>=0;--i) p[i+1]=p[i],w[i+1]=1;
        p[0]=0; w[0]=0; ++n;
    }
    for(int i=0;i<n;++i)
        p[i+n]=p[i]+2*l,w[i+n]=w[i];
    n<<=1;
    if (p[n-1]!=4*l) {
        p[n]=4*l; w[n]=w[0]; ++n;
    }
    double last=0,d=1.0*l*v1/(v1+v2),curl=0,curr=d;
    double L=0,R=l;
    for(int t=0;t<400;++t) {
        double m=(L+R)/2;
        if (can(v1,v2,l,0,m)) L=m;
        else R=m;
    }
    d=R; curr=d;
    int cnt=0,cl=1,cr=1;
    for(int i=0;i<2*n;++i) {
        if (p[i]+eps2<d) cr=i+1,cnt+=w[i];
        else if (p[i]-eps2<d) cr=i+1;
        else break;
    }
    for(int t=0;;++t) {
        double d1=p[cl]-curl,d2=p[cr]-curr,val=min(d1,d2);
        if (fabs(curl-p[cl-1])<eps2) cnt-=w[cl-1];
        if (fabs(curr-p[cr-1])<eps2) cnt+=w[cr-1];
        if (d1+eps2<d2) cl++;
        else if (d2+eps2<d1) cr++;
        else cl++,cr++;
        ans[cnt]+=val;
        curl+=val; curr+=val;
        if (fabs(curl-2*l)<eps2) break;
    }
    for(int i=0;i<=N;++i)
        printf("%.12lf\n",ans[i]/2/l);
    return 0;
}