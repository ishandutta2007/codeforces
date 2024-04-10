#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105];
    int Max=0;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
        pq.push(a[i]);
    }
    Max+=m;
    while(m--){
        int x=pq.top();
        pq.pop();
        pq.push(x+1);
    }
    int Min;
    while(!pq.empty()){
        Min=pq.top();
        pq.pop();
    }
    printf("%d %d\n",Min,Max);
}