#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

char mm[1001][1001];

pair <int,int> q[2002002];
int d[2002002];
vector <pair<int,int> > rows[1002],cols[1002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s\n",&mm[i]);
    if (n==1) {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j)
            if (mm[i][j]=='#') {
                rows[i].push_back(make_pair(i,j));
                cols[j].push_back(make_pair(i,j));
            }
    }
    int qt=0;
    for(int j=0;j<m;++j) {
        if (mm[n-1][j]=='#') {
            q[qt]=make_pair(n-1,j);
            d[qt++]=1;
        }
    }
    bool wasR[1002]={0},wasC[1002]={0};
    wasR[n-1]=true;
    int qh=0;
    while(qh<qt) {
        int dd=d[qh];
        pair <int,int> cur=q[qh++];
        if (cur.first==0) {
            printf("%d\n",dd);
            return 0;
        }
        if (!wasR[cur.first]) {
            for(int i=0;i<rows[cur.first].size();++i) {
                q[qt]=rows[cur.first][i];
                d[qt++]=dd+1;
            }
            wasR[cur.first]=true;
        }
        if (!wasC[cur.second]) {
            for(int i=0;i<cols[cur.second].size();++i) {
                q[qt]=cols[cur.second][i];
                d[qt++]=dd+1;
            }
            wasC[cur.second]=true;
        }
    }
    printf("-1\n");
    return 0;
}