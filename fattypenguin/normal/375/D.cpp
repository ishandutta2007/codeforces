#include <functional>
#include <algorithm>
#include <tr1/unordered_map>
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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

#define keyTree (ch[ ch[root][1] ][0])

const int maxn = 422222;

struct SplayTree{
    //0 
    int sz[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int top1 , top2;
    int ss[maxn], que[maxn];

    inline void Rotate(int x,int f) {
        int y = pre[x];
        push_down(y);
        push_down(x);
        ch[y][!f] = ch[x][f];
        pre[ ch[x][f] ] = y;
        pre[x] = pre[y];
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
        ch[x][f] = y;
        pre[y] = x;
        push_up(y);
    }
    inline void Splay(int x,int goal,int &root) {
        push_down(x);
        while(pre[x] != goal) {
            if(pre[pre[x]] == goal) {
                Rotate(x , ch[pre[x]][0] == x);
            } else {
                int y = pre[x] , z = pre[y];
                int f = (ch[z][0] == y);
                if(ch[y][f] == x) {
                    Rotate(x , !f) , Rotate(x , f);
                } else {
                    Rotate(y , f) , Rotate(x , f);
                }
            }
        //    assert(x);
        }
        push_up(x);
        if(goal == 0) root = x;
    }

    inline void erase(int x) {//x,
        int father = pre[x];
        int head = 0 , tail = 0;
        for (que[tail++] = x ; head < tail ; head ++) {
            ss[top2 ++] = que[head];
            if(ch[ que[head] ][0]) que[tail++] = ch[ que[head] ][0];
            if(ch[ que[head] ][1]) que[tail++] = ch[ que[head] ][1];
        }
        ch[ father ][ ch[father][1] == x ] = 0;
    //    push_up(father);
    }
    ////////////////////////////////////////////////////////////////////////////////
    int get(int key, int &root)
    {
        int x = root;
        while (true)
        {
            if (key == val[x]) return x;
            if (key < val[x]) x = ch[x][0];
            else x = ch[x][1];
        //    assert(x);
        }
       // assert(false);
    }
    void insert(int key, int &root)
    {
        if (root == 0)
        {
            NewNode(root, key);
            return;
        }
        int x = root;
        while (true)
        {
            push_down(x);
            ++sz[x];
            //up
            //Splay!
            if (key < val[x])
            {
                if (!ch[x][0])
                {
                    NewNode(ch[x][0],key);
                    pre[ch[x][0]] = x;
                    x = ch[x][0];
                    break;
                }
                x = ch[x][0];
            }
            else
            {
                if (!ch[x][1])
                {
                    NewNode(ch[x][1],key);
                    pre[ch[x][1]] = x;
                    x = ch[x][1];
                    break;
                }
                x = ch[x][1];
            }
        }
        Splay(x, 0, root);
    }

    inline void del(int x, int &root)
    {
        Splay(x, 0, root);
        int y = ch[x][0];
        while (ch[y][1] != 0)
        {
            push_down(y);
            y = ch[y][1];
        }

        int z = ch[x][1];
        while (ch[z][0] != 0)
        {
            push_down(z);
            z = ch[z][0];
        }
        if (y) Splay(y,0,root);
        if (z) Splay(z,y,root);
        if (z && y) erase(keyTree);
        else if (y) erase(ch[root][1]);
        else if (z) erase(ch[root][0]);
        else if (!z && !y) erase(root), root = 0;
        else assert(false);
        if (z) push_up(z);
        if (y) push_up(y);
    }

    inline int find(int root, int key) {
      int x = root;
      while (1) {
        if (val[x] == key) return x;
        if (val[x] < key) {
          x = ch[x][1];
        } else {
          x = ch[x][0];
        }
      }
      return x;
    }

    inline void remove(int &root, int key) {
      del(find(root, key), root);
    }

    int combine(int r1, int r2)
    {
        dfs(r2,r1);
        erase(r2);
        return r1;
    }

    void dfs(int x, int &r)
    {
        if (ch[x][0]) dfs(ch[x][0],r);
        insert(val[x],r);
        if (ch[x][1]) dfs(ch[x][1],r);
    }

    /******** addpre!!! ***********/
    inline void NewNode(int &x,int c) {
        if (top2) x = ss[--top2];//
        else x = ++top1;
        ch[x][0] = ch[x][1] = pre[x] = 0;
        sz[x] = 1;

        val[x] = c;/**/
    }

    //
    inline void push_down(int x) {/**/
    }
    //
    inline void push_up(int x) {
        sz[x] = 1 + sz[ ch[x][0] ] + sz[ ch[x][1] ];
    }

    inline void prep()
    {
        val[0] = ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;

        top1 = top2 = 0;
    }

    inline void init(int &root) {/**/
 /*       NewNode(root, -0x7f7f7f7f);
        NewNode(ch[root][1], 0x7f7f7f7f);
        pre[ch[root][1]] = root;
        push_up(root); */
        root = 0;
    }

    int getLessOrEqualsThanK(int &root, int k) {
      int res = 0, lastNode, x = root;
      while (x > 0) {
      	lastNode = x;
        if (val[x] < k) {
          x = ch[x][1];
        } else {
          res += sz[ch[x][1]] + 1;
          x = ch[x][0];
        }
      }
      Splay(lastNode, 0, root);
      return res;
    }

    int getKth(int k, int &root)
    {
        int x = root;
        while (true)
        {
            push_down(x);
            if (k == sz[ch[x][0]]+1)
                return val[x];
            if (k <= sz[ch[x][0]])
                x = ch[x][0];
            else
            {
                k -= sz[ch[x][0]] + 1;
                x = ch[x][1];
            }
          //  assert(x);
        }
       // assert(false);
    }

    /**/
    int val[maxn];
} *tree;

const int N = 200000;

typedef tr1::unordered_map<int, int> HashTable;

VI edge[N];
int c[N];

HashTable tables[N];
int root1[N];
int root2[N];

int ans[N];
vector<PII> queries[N];

int n, q;

void append(int from, int to) {
  tree->erase(root2[from]);
  TR(it, tables[root1[from]]) {
    if (tables[root1[to]].find(it->first) == tables[root1[to]].end()) {
      tables[root1[to]][it->first] = it->second;
      tree->insert(it->second, root2[to]);
    } else {
      tree->remove(root2[to], tables[root1[to]][it->first]);
      tables[root1[to]][it->first] += it->second;
      tree->insert(tables[root1[to]][it->first], root2[to]);
    }
  }
}

void dfs(int x, int fa) {
  root1[x] = x;
  tables[root1[x]][c[x]] = 1;
  tree->insert(1, root2[x]);
  TR(it, edge[x]) {
    if (*it == fa) continue;
    dfs(*it, x);
    if (tables[root1[*it]].size() > tables[root1[x]].size()) {
      append(x, *it);
      root1[x] = root1[*it];
      root2[x] = root2[*it];
    } else {
      append(*it, x);
    }
  }
  TR(it, queries[x]) {
    ans[it->second] = tree->getLessOrEqualsThanK(root2[x], it->first);
  }
}

int main() {
  tree = new SplayTree();
  cin >> n >> q;
  REP(i, n) scanf("%d", &c[i]);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    edge[u].PB(v);
    edge[v].PB(u);
  }
  REP(i, q) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    queries[x].PB(MP(y, i));
  }
  dfs(0, -1);
  REP(i, q) {
    cout << ans[i] << endl;
  }
  return 0;
}