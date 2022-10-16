#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct event {
    int x, y;
    bool entra;
    
    bool operator<(const event& ot) const {
        return x < ot.x;
    }
};

event ev[400010];
const int inv = -1000000001;

multiset<int, greater<int> > heights;
vector< pair<int,int> > line;
int n,h,l,r;

#define mp make_pair

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int minx = 1000000001;
    int maxx = -minx;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &l ,&r);
        minx = min(l, minx);
        maxx = max(r, maxx); 
        ev[2*i].y = ev[2*i+1].y = h;
        ev[2*i].x = l;
        ev[2*i+1].x = r;
        ev[2*i].entra = true;
        ev[2*i+1].entra = false;
   }
   
   ev[2*n].x = minx;
   ev[2*n+1].x = maxx;
   ev[2*n].y = ev[2*n+1].y = 0;
   ev[2*n].entra = true;
   ev[2*n+1].entra = false;
   
   ev[2*n+2].x = maxx+1;
   ev[2*n+2].y = 0;
   ev[2*n+2].entra = true;
   
   n = 2*n+3;
   sort(ev, ev+n);
   
   int prevx = minx, prevh = 0;
   for (int i = 0; i < n; i++) {
        if (ev[i].x != prevx) {
            int curh = *heights.begin();
            if (curh != prevh) {
                line.push_back(mp(prevx, prevh));
                line.push_back(mp(prevx, curh));
                prevh = curh;
            }    
            prevx = ev[i].x;
        }
        
        if (ev[i].entra)
            heights.insert(ev[i].y);
        else
            heights.erase(heights.find(ev[i].y));     
   }
   
   int s = line.size();
   printf("%d\n", s);
   for (int i = 0; i < s; i++) {
        printf("%d %d\n", line[i].first, line[i].second);
   }
}