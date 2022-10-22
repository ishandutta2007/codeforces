#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <cstring>
#define MAXN 1000000001

using namespace std;

map<int, vector<pair<int, int> > > cuts;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int grundy=0;
    for(int i=0; i < k; ++i){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2)
            swap(x1, x2);
        if(y1 > y2)
            swap(y1, y2);
        if(x1 == x2){
            if(cuts[x1].empty())
                grundy^=m;
            cuts[x1].push_back(make_pair(y1, y2));
        }
        else{
            if(cuts[y1+MAXN].empty())
                grundy^=n;
            cuts[y1+MAXN].push_back(make_pair(x1, x2));
        }
    }
    if(n%2 == 0)
        grundy ^= m;
    if(m%2 == 0)
        grundy ^= n;
    for(int i=1; i < n; ++i)
        if(cuts[i].empty()){
            grundy^=m;
            break;
        }
    for(int i=1; i < m; ++i)
        if(cuts[i+MAXN].empty()){
            grundy^=n;
            break;
        }
    for(auto it=cuts.begin(); it != cuts.end(); ++it){
        if(it->first < MAXN)
            it->second.push_back(make_pair(m, m));
        else
            it->second.push_back(make_pair(n, n));
        sort(it->second.begin(), it->second.end());
        int last=0;
        int length=0;
        for(int i=0; i < it->second.size(); ++i){
            if((*it).second[i].first > last)
                length += (*it).second[i].first-last;
            if((*it).second[i].second > last)
                last=(*it).second[i].second;
        }
        grundy^=length;
    }
    if(!grundy){
        printf("SECOND\n");
    }else{
        printf("FIRST\n");
        for(auto it=cuts.begin(); it != cuts.end(); ++it){
            int last=0;
            int length=0;
            for(int i=0; i < it->second.size(); ++i){
                if((*it).second[i].first > last)
                    length += (*it).second[i].first-last;
                if((*it).second[i].second > last)
                    last=(*it).second[i].second;
            }
            if((grundy^length) <= length){
                int l2=0;
                last=0;
                for(int i=0; i < it->second.size(); ++i){
                    if((*it).second[i].first > last){
                        l2 += (*it).second[i].first-last;
                        if(l2 >= (grundy^length)){
                            int a=(*it).second[i].first-l2+(grundy^length);
                            if(it->first > MAXN)
                                printf("%d %d %d %d\n", a, it->first-MAXN, n, it->first-MAXN);
                            else
                                printf("%d %d %d %d\n", it->first, a, it->first, m);
                            return 0;
                        }
                    }
                    if((*it).second[i].second > last)
                        last=(*it).second[i].second;
                }
            }
        }
    }
    return 0;
}