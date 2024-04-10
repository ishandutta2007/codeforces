#include<bits/stdc++.h>
#define maxn 102030
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;
int n,nxt[maxn],k,s,d,p,u,v,r;
bool vis[maxn];
pi a[maxn];

int main()
{
    scanf("%d%d%d",&n,&s,&k);
    printf("? %d\n",s); vis[s]=true;
    fflush(stdout);
    scanf("%d%d",&a[0].x,&a[0].y);
    if (a[0].x>=k) {cout << "! " << a[0].x << endl;return 0;}
    srand(time(0)); p=1;
    while (p<min(1000,n)){
        u=rand()%50;
        v=rand()%n+1; v=v*u%n+1;
        if (vis[v]) continue;
        printf("? %d\n",v); vis[v]=true;
        fflush(stdout);
        scanf("%d%d",&a[p].x,&a[p].y);
        p++;
    }
    sort(a,a+p); r=p-1; while (a[r].x>=k) r--; v=a[r].y;
    while (true){
        if (v==-1){cout << "! " << -1 << endl;return 0;}
        printf("? %d\n",v); vis[v]=true;
        fflush(stdout);
        scanf("%d%d",&d,&r);
        if (d>=k) {cout << "! " << d << endl;return 0;}
        v=r;
    }
    return 0;
}