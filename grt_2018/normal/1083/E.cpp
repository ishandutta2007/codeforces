#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second
#define PB push_back
typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct Rect {
	int x,y;
	LL cost;
	bool operator < (const Rect&r) const {
		return x < r.x;
	}
};

struct Line {
	LL a,b;
	LL value(int&x) const{
		return (LL)a*x+b;
	}
	long double intersect(Line &l)const {
		return (long double)(b - l.b)/(l.a - a);
	}
};

const int nax = 1000*1000+1;
Rect rects[nax];
int n;
deque<Line>hull;
LL ans;

int main() {
	scanf("%d",&n);
	for(int i=0; i<n;i++) {
		scanf("%d%d%lld",&rects[i].x,&rects[i].y,
		&rects[i].cost);
	}
	sort(rects,rects+n);
	hull.push_front({0,0});
	for(int i=0; i<n;i++) {
		int &x = rects[i].y;
		while(hull.size()>=2) {
			if(hull.back().value(x)>hull[hull.size()-2].value(x)) {
				break;
			}
			hull.pop_back();
		}
		LL tmp = (LL)rects[i].x*x - rects[i].cost;
		tmp += hull.back().value(x);
		ans=max(ans,tmp);
		Line cur = {-rects[i].x,tmp};
		while(hull.size()>=2) {
			if(cur.intersect(hull[0]) < hull[0].intersect(hull[1])) {
				break;
			}
			hull.pop_front();
		}
		hull.push_front(cur);
	}
	printf("%lld",ans);
}