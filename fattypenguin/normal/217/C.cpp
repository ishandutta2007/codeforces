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

char opt[1000009];
int match[1000009];

int go(int left, int right)
{
    if (left == right)
        return opt[left] == '?' ? (1 << 2) : (1 << (opt[left] - '0'));

    int l, r;
    if (opt[left] == '(')
        l = go(left+1, match[left]-1);
    else l = go(left, left);

    int rbeg;
    char op;
    if (opt[left] == '(')
    {
        op = opt[match[left]+1];
        rbeg = match[left]+2;
    }
    else
    {
        op = opt[left+1];
        rbeg = left+2;
    }

    if (opt[rbeg] == '(')
        r = go(rbeg+1, match[rbeg]-1);
    else r = go(rbeg, rbeg);

    int ret = 0;
    if (op == '&')
    {
        if ((l & 1) || (r & 1) || ((l & 4) && (r & 4)))
            ret |= 1;
        if ((l & 2) && (r & 2))
            ret |= 2;
        if (((l & 2) && (r & 4)) || ((l & 4) && (r & 2)) || ((l & 4) && (r & 4)))
            ret |= 4;
    }

    if (op == '|')
    {
        if ((l & 1) && (r & 1))
            ret |= 1;
        if ((l & 2) || (r & 2) || ((l & 4) && (r & 4)))
            ret |= 2;
        if (((l & 1) && (r & 4)) || ((l & 4) && (r & 1)) || ((l & 4) && (r & 4)))
            ret |= 4;
    }

    if (op == '^')
    {
        if (((l & 1) && (r & 1)) || ((l & 2) && (r & 2)) || ((l & 4) && (r & 4)))
            ret |= 1;
        if (((l & 1) && (r & 2)) || ((l & 2) && (r & 1)) || ((l & 4) && (r & 4)))
            ret |= 2;
        if (((l & 3) && (r & 4)) || ((l & 4) && (r & 3)))
            ret |= 4;
    }

    return ret;
}


int gao(int left, int right, int val)
{
    if (left == right)
        return opt[left] == '?' ? val : (opt[left] - '0');

    int l, r;
    if (opt[left] == '(')
        l = gao(left+1, match[left]-1, val);
    else l = gao(left, left, val);

    int rbeg;
    char op;
    if (opt[left] == '(')
    {
        op = opt[match[left]+1];
        rbeg = match[left]+2;
    }
    else
    {
        op = opt[left+1];
        rbeg = left+2;
    }

    if (opt[rbeg] == '(')
        r = gao(rbeg+1, match[rbeg]-1, val);
    else r = gao(rbeg, rbeg, val);

    if (op == '&')
        return l & r;
    if (op == '|')
        return l | r;
    return l ^ r;
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", opt);
    int len = strlen(opt);
    if (len == 1)
    {
        if (opt[0] == '?')
            printf("YES\n");
        else printf("NO\n");

        return 0;
    }

    stack<int> mystack;
    REP(i, len)
    {
        if (opt[i] == '(')
            mystack.push(i);
        else if (opt[i] == ')')
        {
            match[mystack.top()] = i;
            mystack.pop();
        }
    }

    int mode = go(1, len-2);
    if ((mode & 4))
        printf("YES\n");
    else printf("NO\n");
	return 0;
}