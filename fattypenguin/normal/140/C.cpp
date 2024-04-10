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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

priority_queue<PII> Q;

MII m;

struct PIII
{
    int a,b,c;
    PIII(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    PIII() {};
};

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    m.clear();
    REP(i,n)
    {
        int a;
        cin>>a;
        m[a]++;
    }
    TR(it,m)
    {
   //     cout << it->first << it->second<<endl;
        Q.push(MP(it->second,it->first));
    }
    vector<PIII> answer;
    while (Q.size() > 2)
    {
        PII a = Q.top(); Q.pop();
       // cout<<a.first<<endl;
        PII b = Q.top(); Q.pop();
        PII c = Q.top(); Q.pop();
        int x[3] = {a.second, b.second, c.second};
        sort(x,x+3);
        answer.PB(PIII(x[2],x[1],x[0]));
        a.first -= 1;
        b.first -= 1;
        c.first -= 1;
        if (a.first) Q.push(a);
        if (b.first) Q.push(b);
        if (c.first) Q.push(c);
    }
    cout << answer.size() << endl;
    TR(it,answer)
    {
        cout <<it->a << " " << it->b << " " << it->c << endl;
    }
    return 0;
}