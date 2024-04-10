#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
int _,n,a[maxn][5],p;
bool check(int x,int y){
    int tot=0;
    for (int i=0;i<5;i++) tot+=a[x][i]<a[y][i];
    return tot>=3;
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=0;j<5;j++)
                scanf("%d",&a[i][j]);
        p=1;
        for (int i=2;i<=n;i++)
            if (!check(p,i)) p=i;
        bool flag=1;
        for (int i=1;i<=n;i++) if (p!=i&&!check(p,i)) {flag=0;break;}
        if (flag) printf("%d\n",p); else puts("-1");
    }
    return 0;
}