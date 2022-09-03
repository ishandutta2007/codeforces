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
#define MXN 10005
#define N (1<<20)
int h[3005][3005];
int main(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    scanf("%d",&h[0][0]);
    LL last=h[0][0];
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            h[i][j]=last;
            last=(last*x+y)%z;
        //    printf("%d ",h[i][j]);
        }
       // printf("\n");
    }
    vector<pii> s[3005];
    int now[3005];
    MEM(now);
    for(int i = 0;i<a-1;i++){
        for(int j =0;j<m;j++){
            while(s[j].size()>now[j]&&s[j].back().y>=h[i][j])
                s[j].pop_back();
            s[j].pb(mp(i,h[i][j]));
        }
    }
    LL ans=0;
    for(int i = a-1;i<n;i++){
        for(int j=0;j<m;j++){
            while(s[j].size()>now[j]&&s[j].back().y>=h[i][j])
                s[j].pop_back();
            s[j].pb(mp(i,h[i][j]));
        }
        vector<pii> tmp;
        int nnow=0;
        for(int j=0;j<b-1;j++){
            while(tmp.size()>nnow&&tmp.back().y>=s[j][now[j]].y)tmp.pop_back();
            tmp.pb(mp(j,s[j][now[j]].y));
        }
        for(int j=b-1;j<m;j++){
            while(tmp.size()>nnow&&tmp.back().y>=s[j][now[j]].y)tmp.pop_back();
            tmp.pb(mp(j,s[j][now[j]].y));
            ans+=tmp[nnow].y;
            if(tmp[nnow].x==j-b+1)
                nnow++;
        }
        for(int j  =0;j<m;j++){
            if(s[j][now[j]].x==i-a+1)now[j]++;
            //s[j].erase(s[j].find(h[i-a+1][j]));
        }
    }
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/