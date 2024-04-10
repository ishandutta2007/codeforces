#include<bits/stdc++.h>
using namespace std;
int _,n,m,b[305*305],c[305*305],a[305][305];
map<int,int>f;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        for (int i=1;i<=n*m;i++){
            scanf("%d",&b[i]);
            c[i]=b[i];
        }
        f.clear();
        sort(c+1,c+n*m+1);
        for (int i=1;i<=n*m;i++){
            if (i>1&&c[i]==c[i-1]) continue;
            f[c[i]]=i;
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=0;
        int ans=0;
        for (int i=1;i<=n*m;i++){
            int id=f[b[i]];
            f[b[i]]++;
            int x=(id-1)/m+1,y=(id-1)%m+1;
            a[x][y]=b[i];
            for (int j=1;j<y;j++) if (a[x][j]>0&&a[x][j]!=b[i]) ++ans;
        }
        cout << ans << endl;
    }
}