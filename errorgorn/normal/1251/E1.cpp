#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a,b;
vector<int> v[200005];
priority_queue<int, vector<int>, greater<int> > pq;
int pref[200005];
int main(){
    int TC;
    scanf("%d",&TC);
    int a,b;
    int curr;
    long long cost;
    while (TC--){
        scanf("%d",&n);
        for (int x=0;x<=n;x++){
            v[x].clear();
            pref[x]=0;
        }
        while (!pq.empty()) pq.pop();
        curr=0;
        cost=0;

        for (int x=0;x<n;x++){
            scanf("%d%d",&a,&b);
            pref[a+1]++;
            v[a].push_back(b);
        }
        for (int x=0;x<n;x++){
            pref[x+1]+=pref[x];
        }
        for (int x=n-1;x>=0;x--){
            for (vector<int>::iterator it=v[x].begin();it!=v[x].end();it++){
                pq.push(*it);
            }
            while (pref[x]+curr<x){
                cost+=pq.top();
                pq.pop();
                curr++;
            }
        }
        printf("%lld\n",cost);
    }
}