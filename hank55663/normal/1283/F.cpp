#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int degree[200005];
    fill(degree,degree+n+1,0);
    for(int i = 1;i<n;i++){
        scanf("%d",&a[i]);
        degree[a[i]]++;
    }
    reverse(a+1,a+n);
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i = 1;i<=n;i++){
        if(degree[i]==0){
            pq.push(i);
        }
    }
    vector<pii> v;
    for(int i = 1;i<n;i++){
        int x=pq.top();
        pq.pop();
        v.pb(mp(x,a[i]));
        if(--degree[a[i]]==0){
            pq.push(a[i]);
        }
    }
    printf("%d\n",a[n-1]);
    reverse(v.begin(),v.end());
    for(auto it:v){
        printf("%d %d\n",it.x,it.y);
    }
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/