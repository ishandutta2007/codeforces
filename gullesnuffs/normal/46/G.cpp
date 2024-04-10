#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#define MAXM 1000000

using namespace std;
pair<int, int> p[1000000];
vector<pair<int, pair<int, int> > > sides;
vector<pair<double, pair<int, int> > > finalSides;

int main()
{
    int n;
    cin >> n;
    for(int a=0; a <= 1000; ++a)
        for(int b=1; b <= 1000; ++b){
            int s=a*a+b*b;
            if(s >= MAXM)
                continue;
            p[s]=make_pair(a, b);
        }
    int parity=0;
    for(int i=1; sides.size() < n+1; ++i){
        if(p[i] == make_pair(0, 0))
            continue;
        sides.push_back(make_pair(i, p[i]));
        parity=(parity+p[i].first+p[i].second)%2;
    }
    for(int i=sides.size()-1; i >= 0; --i){
        int parTmp=(sides[i].second.first+sides[i].second.second)%2;
        if(parity == parTmp){
            sides.erase(sides.begin()+i);
            break;
        }
    }
    int x=0, y=0;
    for(int i=sides.size()-1; i >= 0; --i){
        pair<int, int> P=sides[i].second;
        if((abs(x) > abs(y)) == (P.first < P.second)){
            int t=P.first;
            P.first=P.second;
            P.second=t;
        }
        if(x > 0){
            P.first *= -1;
        }
        if(y > 0)
            P.second *= -1;
        x += P.first;
        y += P.second;
        finalSides.push_back(make_pair(-atan2(P.first, P.second), make_pair(P.first, P.second)));
    }
    assert(x == 0 && y == 0);
    sort(finalSides.begin(), finalSides.end());
    printf("YES\n");
    for(int i=0; i < finalSides.size(); ++i){
        printf("%d %d\n", x, y);
        x += finalSides[i].second.first;
        y += finalSides[i].second.second;
    }
    return 0;
}