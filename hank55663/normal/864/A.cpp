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
    map<int,int> m;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        m[x]++;
    }
    if(m.size()!=2){
        printf("NO\n");
    }
    else{
        if(m.begin()->y!=m.rbegin()->y){
            printf("NO\n");
        }
        else{
            printf("YES\n%d %d\n",m.begin()->x,m.rbegin()->x);
        }
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/