#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int t[200005];
    for(int i = 0;i<n;i++)
        scanf("%d",&t[i]);
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int> > pq2;
    int tot=0,ans=0;
    for(int i = 0;i<n;i++){
        tot+=t[i];
        while(tot>m){
            tot-=pq.top();
            pq2.push(pq.top());
            pq.pop();
            ans++;
        }
        printf("%d ",ans);
        pq.push(t[i]);
        while(pq2.size()&&pq2.top()<pq.top()){
            pq.push(pq2.top());
            tot+=pq2.top();
            pq2.pop();
            ans--;
        }
    }
    printf("\n");
}
/*
m3->m2->m->m4
0 1 2 3 4
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/