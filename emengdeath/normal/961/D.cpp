#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct point{
    long long x,y;
    point(long long X=0,long long Y=0){x=X,y=Y;}
}a[N],d[4];
int n;
point operator-(point&a,point&b){
    return point(a.x-b.x,a.y-b.y);
}
long long operator*(point a,point b){
    return a.x*b.y-a.y*b.x;
}
bool line(point a,point b,point c){
    return (b-a)*(c-a)==0;
}
bool check(point p1,point p2,point p3,point p4){
    for (int i=1;i<=n;i++)
        if (!line(p1,p2,a[i])&&!line(p3,p4,a[i]))return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    d[0]=a[1],d[1]=a[min(2,n)];
    int r=1;
    for (int i=3;i<=n&&r!=3;i++)
        if (!line(d[0],d[1],a[i])){
            if (r==2&&(line(d[0],d[2],a[i])||line(d[1],d[2],a[i])))continue;
            d[++r]=a[i];
        }
    if (r<=1)cout<<"Yes";
    else
    if (r==2)check(d[0],d[1],d[1],d[2])||check(d[0],d[1],d[0],d[2])?cout<<"Yes":cout<<"No";
    else
    check(d[0],d[1],d[2],d[3])||check(d[0],d[2],d[1],d[3])||check(d[0],d[3],d[1],d[2])?cout<<"Yes":cout<<"No";
    return 0;
}