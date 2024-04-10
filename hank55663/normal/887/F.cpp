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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[500005];
    map<int,vector<int>> m;
    set<int> s;
    for(int i = 0;i<n;i++)
    s.insert(i);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]].pb(i);
    }
    int llast=n+k;
    int last=n;
    int cnt=0;
    for(auto it:m){
        if(!cnt&&it.y[0]<last-k){
            auto it = s.lower_bound(llast-k);
            if(it!=s.end())
            last=*it;
            cnt=1;
        }
        if(it.y[0]<last-k){
            printf("NO\n");
            return 0;
        }
        for(auto it2:it.y){
            s.erase(it2);
        }
        llast = last;
        last=min(it.y[0],last);
    }
    printf("YES\n");
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/