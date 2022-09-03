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
double cal(pdd p,pdd q){
    return sqrt(sqr(p.x-q.x)+sqr(p.y-q.y));
}
double cross(pdd p,pdd q){
    return p.x*q.y-p.y*q.x;
}
bool solve(){
    int n,h;
    scanf("%d %d",&n,&h);
    pii p[200005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 0;i<n;i++){
        p[i].x-=p[n-1].x;
        p[i].x=-p[i].x;
        p[i].y-=p[n-1].y+h;
        
    }
    reverse(p,p+n);
    //for(int i = 0;i<n;i++){
    // //   printf("%d %d\n",p[i].x,p[i].y);
    //}
    double ans=0;
    pii Max=mp(0,-100);
    for(int i = 1;i<n;i++){

      //  int gcd1=abs(__gcd(p[i-1].x,p[i-1].y));
      //  int gcd2=abs(__gcd(p[i].x,p[i].y));
        //if(mp(p[i-1].x/gcd1,p[i-1].y/gcd1)==mp(p[i].x/gcd2,p[i].y/gcd2));
        if(cross(p[i],p[i-1])>0){
            if(cross(Max,p[i])>=0){
                ans+=cal(p[i],p[i-1]);
                    Max=p[i-1];
            }
            else if(cross(p[i-1],Max)>=0){
                
            }
            else{
                pdd l=p[i],r=p[i-1];
                for(int i = 0;i<100;i++){
                    pdd mid=mp((l.x+r.x)/2,(l.y+r.y)/2);
                   // double p=atan2(mid.y,mid.x);
                    if(cross(Max,mid)>=0){
                        r=mid;
                    }
                    else{
                        l=mid;
                    }
                }
                ans+=cal(r,p[i-1]);
                    Max=p[i-1];
            }
        
        }
        else{
             if(cross(Max,p[i-1])>=0){
                ans+=cal(p[i],p[i-1]);
                Max=p[i];
            }
            else if(cross(p[i],Max)>=0){
                
            }
            else{
                if(cross(p[i],p[i-1])==0){
                    ans+=cal(p[i],p[i-1]);
                }
                else{
                    pdd l=p[i-1],r=p[i];
                    for(int i = 0;i<100;i++){
                        pdd mid=mp((l.x+r.x)/2,(l.y+r.y)/2);
                    // double p=atan2(mid.y,mid.x);
                        if(cross(Max,mid)>=0){
                            r=mid;
                        }
                        else{
                            l=mid;
                        }
                    }
                    ans+=cal(r,p[i]);
                }
                Max=p[i];
            }
            
        }
      //  printf("%d %d\n",Max.x,Max.y);
    }
    printf("%.12f\n",ans);
    return true;
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
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