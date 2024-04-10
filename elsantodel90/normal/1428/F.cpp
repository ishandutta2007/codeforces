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

string s;

struct Item
{
    tint maxl, pri;
    Item operator +(const Item &o) const { return {maxl + o.maxl, pri + o.pri}; }
    Item operator -(const Item &o) const { return {maxl - o.maxl, pri - o.pri}; }
};

const int MAX = 1000000;

Item items[MAX];
Item tablita[MAX];

tint f(int a,int b)
{
    assert(a < b);
    if (b - a == 1)
        return s[a] - '0';
    int mid = (a+b)/2;
    tint ret = f(a, mid) + f(mid, b);
    items[mid] = {0,0};
    bool seenZero = false;
    tint lastEnding1 = 0;
    //if (a == 0 && b == 6)
    //    cout << "Primera tanda" << endl;
    dforsn(i, a, mid)
    {
        seenZero |= s[i] == '0';
        items[i].pri = items[i+1].pri + !seenZero;
        if (s[i] == '1')
            lastEnding1++;
        else
            lastEnding1 = 0;
        items[i].maxl = max(items[i+1].maxl, lastEnding1);
        //cout << items[i].maxl << " " << items[i].pri << endl;
    }
    tablita[a] = {0,0};
    forsn(i, a, mid)
        tablita[i+1] = tablita[i] + items[i];
    seenZero = false;
    lastEnding1 = 0;
    Item previous = {0,0};
    int pointer1 = mid-1;
    int pointer2 = mid-1;
    //if (a == 0 && b == 6)
    //    cout << "Segunda tanda" << endl;
    forsn(i, mid, b)
    {
        seenZero |= s[i] == '0';
        Item current;
        current.pri = previous.pri + !seenZero;
        if (s[i] == '1')
            lastEnding1++;
        else
            lastEnding1 = 0;
        current.maxl = max(previous.maxl, lastEnding1);
        //cout << current.maxl << " " << current.pri << endl;
        
        // Avanzar los punteros y contar
        while (pointer1 >= a && (items[pointer1].maxl <= items[pointer1].pri + current.pri || items[pointer1].maxl <= current.maxl)) pointer1--;
        while (pointer2 >= a && items[pointer2].maxl <= current.maxl && items[pointer2].pri + current.pri <= current.maxl) pointer2--;
        assert(pointer1 <= pointer2);
        
        tint l1 = pointer1 - (a-1);
        tint l2 = pointer2 - pointer1;
        tint l3 = mid-1 - pointer2;
        assert(l1 + l2 + l3 == mid-a);
        
        //cout << l1 << " " << l2 << " " << l3 << endl;
        
        ret += (tablita[pointer1+1] - tablita[a]).maxl;
        ret += l2 * current.pri + (tablita[pointer2+1] - tablita[pointer1+1]).pri;
        ret += l3 * current.maxl;
        
        previous = current;
    }
    //cout << "f(" << a << "," << b << ") = " << ret << endl;
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin >> s;
    
    cout << f(0, n) << "\n";
    return 0;
}