#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

struct Point {
    int x,y;
};

const int nax = 1001;
Point A,B,C;
int k=nax*nax;
Point res;

int dist(Point D) {
    return 1+abs(A.x-D.x)+abs(A.y-D.y)+abs(B.x-D.x)+abs(B.y-D.y)+abs(C.x-D.x)+abs(C.y-D.y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    for(int i=0; i<nax; i++) {
        for(int j=0; j<nax; j++) {
            Point tmp = {i,j};
            if(dist(tmp)<k) {
                k = dist(tmp);
                res = tmp;
            }
        }
    }
    cout<<k<<"\n";
    cout<<res.x<<" "<<res.y<<"\n";
    while(A.x!=res.x||A.y!=res.y) {
        cout<<A.x<<" "<<A.y<<"\n";
        if(A.x<res.x) A.x++;
        else if(A.x>res.x) A.x--;
        else if(A.y>res.y) A.y--;
        else A.y++;
    }
    while(B.x!=res.x||B.y!=res.y) {
        cout<<B.x<<" "<<B.y<<"\n";
        if(B.x<res.x) B.x++;
        else if(B.x>res.x) B.x--;
        else if(B.y>res.y) B.y--;
        else B.y++;
    }
    while(C.x!=res.x||C.y!=res.y) {
        cout<<C.x<<" "<<C.y<<"\n";
        if(C.x<res.x) C.x++;
        else if(C.x>res.x) C.x--;
        else if(C.y>res.y) C.y--;
        else C.y++;
    }
}