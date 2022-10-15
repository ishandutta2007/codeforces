#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)

#define SIZE(c) int((c).size())

#ifdef LAPTOP_ELAINE
    #define DBG(x) cerr << #x << " = " << (x) << endl
    #define DBG2(x,y) cerr << #x << " = " << (x) << " , " << #y << " = " << (y) << endl
    #define DBG3(x,y,z) cerr << #x << " = " << (x) << " , " << #y << " = " << (y) << #z << " = " << (z) << endl
    #define RAYA cerr << "============================" << endl
#else
    #define DBG(x) do {} while (false)
    #define DBG2(x,y) do {} while (false)
    #define DBG3(x,y,z) do {} while (false)
    #define RAYA do {} while (false)
#endif

#define esta(x,c) ((c).find(x) != (c).end())
#define all(c) (c).begin(), (c).end()

typedef long long tint;
typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

struct Level
{
    int a,b;
    int diff() const { return b-a; }
};

const int MAXN = 500000;

Level v[MAXN];
int status[MAXN];
int n,w;
struct Item
{
    tint cost;
    int index;
    
    const Level & level() const { return v[index]; }
    
    bool operator <(const Item &o) const { return cost < o.cost || (cost == o.cost && index < o.index); }
};

const tint INF = 1000000000000000000LL;

tint work()
{
    forn(i,n)
        status[i] = 0;
    set<Item> remaining, remainingFull, used;
    forn(i,n)
    {
        remaining.insert({v[i].a, i});
        remainingFull.insert({v[i].b, i});
    }
    tint best = 0;
    forn(steps, w)
    {
        Item bs = *remaining.begin();
        if (!used.empty() && !remainingFull.empty())
        {
            Item worst = *used.rbegin();
            Item bestFull = *remainingFull.begin();
            if (bestFull.cost - worst.cost < bs.cost)
            {
                best += bestFull.cost - worst.cost;
                
                remaining.erase({bestFull.level().a, bestFull.index});
                status[bestFull.index] = 2;
                remainingFull.erase(bestFull);
                
                used.erase(worst);
                if (--status[worst.index] == 1)
                    used.insert({worst.level().a, worst.index});
                else
                {
                    remaining.erase({worst.level().diff(), worst.index});
                    remainingFull.insert({worst.level().b , worst.index});
                }
                remaining.insert(worst);
                continue;
            }
        }
        best += bs.cost;
        remaining.erase(bs);
        remainingFull.erase({bs.level().b, bs.index});
        used.erase({bs.level().a, bs.index});
        used.insert(bs);
        if (++status[bs.index] < 2)
            remaining.insert({bs.level().diff(), bs.index});
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> w;
    
    forn(i,n)
        cin >> v[i].a >> v[i].b;
        
    cout << work() << "\n";
    forn(i,n)
        cout << status[i];
    cout << "\n";
    
    
    return 0;
}