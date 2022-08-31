#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _,vis[10005],p[10005],last,n;
int ask(int x){
    printf("? %d\n",x);
    fflush(stdout);
    int ret; 
    scanf("%d",&ret);
    return ret;
}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) vis[i]=0;
        for (int i=1;i<=n;i++) if (!vis[i]){
            last=ask(i);
            vis[last]=1;
            while (1){
                int x=ask(i);
                p[last]=x;
                if (vis[x]) break;
                vis[x]=1; last=x;
            }
        }
        printf("!");
        for (int i=1;i<=n;i++) printf(" %d",p[i]);puts("");
    }
    return 0;
}