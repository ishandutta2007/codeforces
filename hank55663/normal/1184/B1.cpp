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
#define MXN 10005
#define less Less
int main(){
    int s,b;
    scanf("%d %d",&s,&b);
    int a[100005];
    for(int i = 0;i<s;i++)
        scanf("%d",&a[i]);
    pii p[100005];
    for(int i = 1;i<=b;i++){
        int d,g;
        scanf("%d %d",&d,&g);
        p[i]=mp(d,g);
    }
    sort(p+1,p+b+1);
    map<int,int> m;
    int sum=0;
    m[0]=0;
    for(int i = 1;i<=b;i++){
        sum+=p[i].y;
        m[p[i].x]=sum;
    }
    for(int i = 0;i<s;i++){
        auto it=m.upper_bound(a[i]);
        it--;
        printf("%d%c",it->y," \n"[i==s-1]);
    }
}