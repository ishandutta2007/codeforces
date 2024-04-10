#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <list>
using namespace std;

int x[100005];
list<int> l;
set<int> s;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", x+i);
        if(s.find(x[i]) != s.end())
            continue;
        l.push_back(x[i]);
        s.insert(x[i]);
    }
    int a, b;
    scanf("%d%d", &a, &b);
    int ans=0;
    while(a > b){
        int best=a-1;
        for(list<int>::iterator it=l.begin(); it != l.end(); ){
            if(a-(a%(*it)) < b){
                it=l.erase(it);
                continue;
            }
            else if(a-(a%(*it)) < best){
                best=a-(a%(*it));
            }
            ++it;
        }
        a=best;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}