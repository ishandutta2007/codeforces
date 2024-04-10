#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "cowart.in", "r", stdin );
#define fout freopen( "cowart.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a,i;
    string b[10]={ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"  },c[10]={ "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"  };
    string d[10]={ "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    cin>>a;
    if( a>10 && a<20 )cout<<d[a%10];
    else if( a<10 )cout<<b[a];
    else if( a==10 || a==20 || a==30 || a==40 || a==50 || a==60 || a==70 || a==80 || a==90 )cout<<c[a/10];
    else cout<<c[a/10]<<"-"<<b[a%10];
}