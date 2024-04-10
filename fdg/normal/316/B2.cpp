#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

int in[1002],nx[1002];
bool can[2002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,a,add=0;
    scanf("%d%d",&n,&k); --k;
    for(int i=0;i<n;++i) {
        scanf("%d",&nx[i]); nx[i]--;
        if (nx[i]>=0) in[nx[i]]++;
    }
    vector <int> v;
    for(int i=0;i<n;++i) {
        if (in[i]==0||i==k) {
            int cur=i,len=0;
            bool was=false;
            while(cur!=-1) {
                ++len;
                if (cur==k) len=0,was=true;
                cur=nx[cur];
            }
            if (!was) v.push_back(len);
            else add=len;
        }
    }
    can[0]=true;
    for(int j=0;j<v.size();++j)
        for(int i=1000;i>=0;--i) {
            if (can[i]) can[i+v[j]]=true;
        }
    for(int i=0;i<=1000;++i)
        if (can[i]) printf("%d\n",i+add+1);
    return 0;
}