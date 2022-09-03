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
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i+1);
    }
    sort(p,p+n);
    vector<int> v;
    map<int,int> m;
    for(int i=1;i<n;i++){
        v.pb(p[i].x-p[i-1].x);
        m[v.back()]++;
    }
    for(int i = 1;i<n-1;i++){
        if(--m[v[i-1]]==0){
            m.erase(v[i-1]);
        }
        if(--m[v[i]]==0){
            m.erase(v[i]);
        }
        m[p[i+1].x-p[i-1].x]++;
        if(m.size()==1){
            printf("%d\n",p[i].y);
            return 0;
        }
        m[v[i-1]]++;
        m[v[i]]++;
        if(--m[p[i+1].x-p[i-1].x]==0){
            m.erase(p[i+1].x-p[i-1].x);
        }
    }
    if(--m[v[0]]==0){
        m.erase(v[0]);
    }
    if(m.size()==1||m.size()==0){
        printf("%d\n",p[0].y);
        return 0;
    }
    m[v[0]]++;
    if(--m[v.back()]==0){
        m.erase(v.back());
    }
    if(m.size()==1||m.size()==0){
        printf("%d\n",p[n-1].y);
        return 0;
    }
    printf("-1\n");
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