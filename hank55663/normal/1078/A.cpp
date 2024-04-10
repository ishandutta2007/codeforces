/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
vector<pii> v[300005];
double dis(const pdd &a,const pdd &b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int main(){
    LL a,b,c;
    LL x1,y1,x2,y2;
    scanf("%lld %lld %lld",&a,&b,&c);
    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    double ans=abs(x1-x2)+abs(y1-y2);
    if(b!=0){
        double xx1=x1  ,yy1=(double)(-a*x1-c)/b;
        double xx2=x2  ,yy2=(double)(-a*x2-c)/b;
        ans=min(ans,dis(mp(xx1,yy1),mp(xx2,yy2))+abs(yy1-y1)+abs(yy2-y2));
    }
    if(a!=0){
        double xx1=(double)(-b*y1-c)/a,  yy1=y1;
        double xx2=(double)(-b*y2-c)/a,  yy2=y2;
        ans=min(ans,dis(mp(xx1,yy1),mp(xx2,yy2))+abs(xx1-x1)+abs(xx2-x2));
    }
    if(a!=0&&b!=0){

        {
            double xx1=(double)(-b*y1-c)/a,  yy1=y1;
            double xx2=x2  ,yy2=(double)(-a*x2-c)/b;
            ans=min(ans,dis(mp(xx1,yy1),mp(xx2,yy2))+abs(xx1-x1)+abs(yy2-y2));
        }
        {
            double xx1=x1  ,yy1=(double)(-a*x1-c)/b;
            double xx2=(double)(-b*y2-c)/a,  yy2=y2;
            ans=min(ans,dis(mp(xx1,yy1),mp(xx2,yy2))+abs(xx2-x2)+abs(yy1-y1));
        }
    }
    printf("%.12f\n",ans);
}