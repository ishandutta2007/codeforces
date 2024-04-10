#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back
#define Det(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))

struct P {
    LL x,y;
};

const int INF = 1000*1000*1000;
const int MAXN = 1000*100+10;
int n;
P points[MAXN];
P lowest={INF,INF};
P highest={-INF,-INF};

bool cmp(P &a, P&b) {
    if(Det(lowest,a,b)==0) {
        if(a.x-lowest.x==b.x-lowest.x)
            return a.y-lowest.y<b.y-lowest.y;
        return a.x-lowest.x<b.x-lowest.x;
    }
    return Det(lowest,a,b)<0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>points[i].x>>points[i].y;
        points[i].y-=points[i].x*points[i].x;
        if(points[i].x<lowest.x) lowest = points[i];
        if(points[i].x==lowest.x&&points[i].y>lowest.y) lowest = points[i];
        if(points[i].x>highest.x) highest = points[i];
        if(points[i].x==highest.x&&points[i].y>highest.y) highest = points[i];
    }
    sort(points,points+n,cmp);
    //cout<<"SortByAngle : \n";
    //for(int i=0; i<n;i++) {
    //    cout<<points[i].x<<" "<<points[i].y<<"\n";
    //}
    vector<P>hull = {lowest};
    bool endq=0;
    for(int i=0; i<n;i++) {
        if(points[i].x==lowest.x&&points[i].y==lowest.y) continue;
        if(points[i].x==highest.x&&points[i].y==highest.y) endq=1;
        while(hull.size()>1&&Det(hull[hull.size()-2],points[i],hull.back())<=0)
            hull.pop_back();
        hull.PB(points[i]);
        if(endq) break;
    }
    if(hull.size()>1&&hull.back().x==hull[hull.size()-2].x) hull.pop_back();
    cout<<hull.size()-1;
}