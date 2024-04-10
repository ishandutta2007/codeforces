#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

map<int,int> BIT;
int n,q;


class Node
{
    int s;
    Node *lc,*rc;
    Node* getl() {return lc == NULL ? lc = new Node() : lc;}
    Node* getr() {return rc == NULL ? rc = new Node() : rc;}
public:
    Node(): s(0),lc(NULL),rc(NULL) {}
    ~Node() {delete lc,delete rc; }
    void add(int l,int r,int where,int delta)
    {
        s += delta;
        if (l < r)
        {
            int mid = (l+r)>>1;
            if (where <= mid)
                getl()->add(l,mid,where,delta);
            else getr()->add(mid+1,r,where,delta);
        }
    }
    int sum(int l,int r,int where)
    {
        if (!s || r <= where)
            return s;
        int mid = (l+r)>>1;
        if (where <= mid)
            return getl()->sum(l,mid,where);
        else return getl()->sum(l,mid,where) + getr()->sum(mid+1,r,where);
    }
} *root;

inline int LB(int x) {return x & -x;}

void I( int x , int val )
{
    /*
     for ( int i = x ; i <= n ; i += i & ( -i ) ) BIT[ i ] += val;
    */
    root->add(1,n,x,val);
}

int Q( int x )
{
    /*
    int res = 0;
    for ( int i = x ; i >= 1 ; i -= i & ( -i ) )
      if ( BIT.find( i ) != BIT.end() ) res += BIT[ i ];
    return( res );
    */
    return root->sum(1,n,x);
}


map<int,int> pos,per;
map<pair<int,int>,int> inv;

int main()
{
    root = new Node();
    cin >> n >> q;
    pos[0] = pos[n+1] = 1;
    inv[MP(-n,-1)] = 1;
    for (int i = 0;i < q;++i)
    {
        int kind;
        scanf("%d",&kind);
        if (0 == kind)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",Q(r)-Q(l-1));
        }
        else
        {
            int x = kind;
            if (per.find(x) == per.end())
            {
                map<pair<int,int>,int>::iterator it = inv.begin();
                int length = -(it->first).first,start = -(it->first).second;
                inv.erase(it);
                pair<int,int> left,right;
                if (length&1)
                    left = MP(-length/2,-start),
                    right = MP(-length/2,-(start+length/2+1));
                else
                    left = MP(-length/2,-start),
                    right = MP(-length/2+1,-(start+length/2+1));
                if (length == 2)
                    inv[left] = 1;
                else if (length > 1)
                    inv[left] = 1,inv[right] = 1;
                per[x] = start + length/2;
                pos[start+length/2] = 1;
                //cout << "position is " << per[x] << endl;
                //cout << left.first << " " << left.second << endl;
                //cout << right.first << " " << right.second << endl;
                I(start+length/2,1);
            }
            else
            {
                map<int,int>::iterator it = per.find(x);
                int where = it->second;
                per.erase(it);
                int beg,len;
                it = pos.find(where);
                --it;
                beg = it->first + 1;
              //  cout << "beg = " << beg << endl;
                if (beg < where)
                    inv.erase(inv.find(MP(-where+beg,-beg)));
                it = pos.find(where);
                ++it;
                len = it->first - beg;
          //      cout << "next = " << it->first << endl;
                if (where+1<it->first)
                    inv.erase(inv.find(MP(-(it->first-where-1),-where-1)));
                pos.erase(pos.find(where));
            //    cout << beg << "    " << len << endl;
                inv[MP(-len,-beg)] = 1;
                I(where,-1);
            }
        }
    }
    return 0;
}