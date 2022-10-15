#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const tint INF = 1000000000000000000LL;

#define MAXN 1100000

struct Info
{
    tint sum, best;
    Info () {sum = 0; best = -INF;}
    
    void merge(const Info &a, const Info &b)
    {
        sum = a.sum + b.sum;
        best = max(a.best, a.sum + b.best);
    }
    
    void setweapon(tint cost)
    {
        best = max(best, -cost);
    }
};

struct rmq {
    typedef Info tipo;
	int MAX;
	tipo vec[4*MAXN];
	void init(int n) {
		MAX = 1 << (32-__builtin_clz(n)); 
		//fill(vec, vec+2*MAX, 0); // 0 = elemento neutro
		//return vec+MAX;
	}
	void paddmonster(int i, tint delta) {
		vec[i+=MAX].sum += delta;
		recalc(i);
	}
    void psetweapon(int i, tint cost) {
		vec[i+=MAX].setweapon(cost);
		recalc(i);
	}
    void recalc(int i) {
        while(i) { i /= 2; vec[i].merge(vec[2*i], vec[2*i+1]); } // + = operacion
    }
	//tipo pget(int i, int j) { return _pget(i+MAX, j+MAX); }
	//tipo _pget(int i, int j) {
	//	tipo res = 0;             // 0 = elemento neutro
	//	if (j-i <= 0) return res;
	//	if (i%2) res += vec[i++]; // + = operacin
	//	res += _pget(i/2, j/2);   // + = operacin
	//	if (j%2) res += vec[--j]; // + = operacin
	//	return res;
	//}
} st;

const int ARMOR = 0;
const int MONSTER = 1;

struct Point
{
    int x,y;
    tint score;
    int type;
    bool operator<(const Point &o) const
    {
        return x < o.x || (x == o.x && type < o.type);
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    st.init(MAXN);
    int n,m,p;
    cin >> n >> m >> p;
    forn(i,n)
    {
        int a; tint cost;
        cin >> a >> cost;
        st.psetweapon(a, cost);
    }
    vector<Point> points(m+p);
    forn(i,m)
    {
        Point &armor = points[i];
        cin >> armor.x >> armor.score;
        armor.score = -armor.score;
        armor.type = ARMOR;
    }
    forn(i,p)
    {
        Point &monster = points[m+i];
        cin >> monster.y >> monster.x >> monster.score;
        monster.type = MONSTER;
    }
    sort(all(points));
    tint grandBest = -INF;
    for (const auto &pun : points)
    {
        if (pun.type == ARMOR)
        {
            grandBest = max(grandBest, st.vec[1].best + pun.score);
        }
        else
        {
            st.paddmonster(pun.y, pun.score);
        }
    }
    cout << grandBest << endl;
    return 0;
}