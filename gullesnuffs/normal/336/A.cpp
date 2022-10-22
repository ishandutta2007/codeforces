#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    pair<int, int> p1, p2;
    p1=make_pair(0, y>0?(abs(x)+abs(y)):-(abs(x)+abs(y)));
    p2=make_pair(x>0?(abs(x)+abs(y)):-(abs(x)+abs(y)), 0);
    if(p1 > p2)
        swap(p1, p2);
    printf("%d %d %d %d\n", p1.first, p1.second, p2.first, p2.second);
    return 0;
}