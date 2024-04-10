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

priority_queue<pair<int,int> > Q;
vector<pair<int,pair<int,int> > > s;
VI answer;
int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    REP(i,k)
    {
        int a,b;
        cin>>a>>b;
        s.PB(MP(n-b,MP(a-1,i)));
    }
    SORT(s);
    int now = 0;
    for (int i = 0;i < n;++i)
    {
        while (now<k&&s[now].first<=i) Q.push(MP(-s[now].second.first,s[now].second.second)),now++;
        while (Q.size() && -Q.top().first < i) Q.pop();
        if (Q.size()) answer.PB(Q.top().second+1), Q.pop();
    }
    cout << answer.size() << endl;
    SORT(answer);
    REP(i,answer.size())
    {
        if (i) cout << " ";
        cout << answer[i];
    }
    return 0;
}