#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,t,c;
    vector <pair<int,int> > v1,v2;
    int cost[1002],type[1002];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&c,&t);
        if (t==1) v1.push_back(make_pair(c,i));
        else v2.push_back(make_pair(c,i));
        cost[i]=c; type[i]=t;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    double sum=0;
    vector < vector <int> > v(k);
    int cur=k-1;
    for(int i=v1.size()-1;i>=0;--i) {
        v[cur].push_back(v1[i].second);
        if (cur>0) --cur;
    }
    for(int i=v2.size()-1;i>=0;--i) {
        v[cur].push_back(v2[i].second);
        if (cur>0) --cur;
    }
    for(int i=0;i<k;++i) {
        int mn=cost[v[i][0]]; bool was=false;
        for(int j=0;j<v[i].size();++j) {
            sum+=cost[v[i][j]];
            if (cost[v[i][j]]<mn) mn=cost[v[i][j]];
            if (type[v[i][j]]==1) was=true;
        }
        if (was) sum-=0.5*mn;
    }
    printf("%.1lf\n",sum);
    for(int i=0;i<k;++i) {
        printf("%d",v[i].size());
        for(int j=0;j<v[i].size();++j)
            printf(" %d",v[i][j]+1);
        printf("\n");
    }
    return 0;
}