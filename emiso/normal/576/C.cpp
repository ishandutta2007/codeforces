#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>

#define X first.first
#define Y first.second

using namespace std;

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    int xa = a.X/1000;
    int xb = b.X/1000;
    if(xa == xb) {
        if(xa%2) return a.Y > b.Y;
        return a.Y < b.Y;
    }
    return (xa < xb)?1:0;
}

vector <pair<pair<int,int>,int> > p;

int main() {
    int n,x,y;
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        p.push_back(make_pair(make_pair(x,y),i+1));
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",p[i].second);
    return 0;
}