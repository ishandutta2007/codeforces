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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        map<pii,int> m;
        m[mp(0,0)]=0;
        int n;
        scanf("%d",&n);
        char c[200005];
        scanf("%s",c+1);
        int x=0,y=0;
        pii ans=mp(1,1e9);
        for(int i = 1;c[i]!=0;i++){
            if(c[i]=='U')x++;
            if(c[i]=='D')x--;
            if(c[i]=='R')y++;
            if(c[i]=='L')y--;
            if(m.find(mp(x,y))!=m.end()){
                int l=m[mp(x,y)],r=i;
                if(r-l<ans.y-ans.x)ans=mp(l,r);
            }
            m[mp(x,y)]=i;
        }
        if(ans.y==1e9)printf("-1\n");
        else printf("%d %d\n",ans.x+1,ans.y);
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/