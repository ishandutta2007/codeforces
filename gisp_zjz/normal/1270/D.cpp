#include<bits/stdc++.h>
#define pb push_back
using namespace std;
map <int,int> f;
int n,k;
int main(){
    cin >> n >> k;
    for (int i=1;i<=k+1;i++){
        printf("?");
        for (int j=1;j<=k+1;j++) if (j!=i) printf(" %d",j); puts("");
        fflush(stdout);
        int x,y; scanf("%d%d",&x,&y);
        f[y]++;
    }
    int res=0;
    for (auto x:f) res=x.second;
    printf("! %d\n",res);
    return 0;
}