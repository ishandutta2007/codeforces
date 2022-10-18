#include <stdio.h>
#include <math.h>
#include <set>
#define FOR(i,N) for(i=0;i<N;i++)

using namespace std;

struct Point {
    long long x,y;
    Point flip() const{
        Point pt;
        pt.x = x;
        pt.y = -y;
        return pt;
    }
    bool operator< (const Point& pt) const{return x < pt.x || (x == pt.x && y < pt.y);}
};

typedef set<Point> PointMap;

bool Above(Point p, Point a, Point b){
  return (p.y - a.y) * (b.x - a.x) > (b.y - a.y) * (p.x - a.x);
}

void AddPoint(PointMap& envelope, Point pt){
    PointMap::iterator rightNeighbour = envelope.lower_bound(pt);
    PointMap::iterator insertPoint = envelope.end();
    if(rightNeighbour == envelope.end()){
        PointMap::iterator leftNeighbour = envelope.end();
        leftNeighbour--;
        insertPoint = envelope.insert(pt).first;
    } else
    if(rightNeighbour == envelope.begin()){
        if(rightNeighbour->x == pt.x) return;
        insertPoint = envelope.insert(pt).first;
    }
    else{
        PointMap::iterator leftNeighbour(rightNeighbour);
        leftNeighbour--;
        if(Above(pt, *leftNeighbour, *rightNeighbour)) insertPoint = envelope.insert(pt).first;
    }
    if(insertPoint != envelope.end()){
        if(insertPoint != envelope.begin()){
            PointMap::iterator prev = insertPoint;
            prev--;
            while(prev != envelope.begin()){
                PointMap::iterator pprev = prev;
                pprev--;
                if(!Above(*prev, *pprev, *insertPoint)){
                    envelope.erase(prev);
                    insertPoint = envelope.find(pt);
                    prev = insertPoint;
                    prev--;
                } else break;
            }
        }
        if(insertPoint != --envelope.end()){
            PointMap::iterator next = insertPoint;
            next++;
            while(next != --envelope.end()){
                PointMap::iterator nnext = next;
                nnext++;
                if(!Above(*next, *insertPoint, *nnext)){
                    envelope.erase(next);
                    insertPoint = envelope.find(pt);
                    next = insertPoint;
                    next++;
                } 
                else break;
            }
        }
    }
}

bool over(PointMap& envelope, Point pt){
    PointMap::iterator rightNeighbour = envelope.lower_bound(pt);
    if(rightNeighbour == envelope.end()){
      PointMap::iterator leftNeighbour = --envelope.end();
      if((leftNeighbour->x) == pt.x) return pt.y>(leftNeighbour->y);
      return true;
    }
    if(rightNeighbour == envelope.begin()){
      if((rightNeighbour->x) == pt.x) return pt.y>(rightNeighbour->y);
      return true;
    }
    PointMap::iterator leftNeighbour(rightNeighbour);
    --leftNeighbour;
    return Above(pt, *leftNeighbour, *rightNeighbour);
}

int main(){
  int Q,q,i,x,y;
  scanf("%d",&Q);
  PointMap upper, lower;
  scanf("%d%d%d",&q,&x,&y);
  Point pt;
  pt.x=x;
  pt.y=y;
  upper.insert(pt);
  lower.insert(pt.flip()); 
  FOR(i,Q-1){
    scanf("%d%d%d",&q,&x,&y);
    Point pt;
    pt.x=x;
    pt.y=y;
    if(q==1){
      AddPoint(upper, pt);
      AddPoint(lower, pt.flip());
    }
    else{
      if(over(upper,pt)||over(lower,pt.flip())) printf("NO\n");
      else printf("YES\n");
    }
  }
  return 0;
}