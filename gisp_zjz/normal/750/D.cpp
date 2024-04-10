#include<bits/stdc++.h>
#define maxn 230000

using namespace std;
bool t[500][500];
int ans,n,a[40],f[40][500][500];
int x[8]={1,1,0,-1,-1,-1,0,1};
int y[8]={0,1,1,1,0,-1,-1,-1};

int main(){
    f[0][250][250]=1;
    cin >> n; for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        for (int j=0;j<500;j++)
            for (int k=0;k<500;k++)
                for (int r=0;r<8;r++) if (f[i-1][j][k]&(1<<r)){
                    for (int w=1;w<=a[i];w++) t[j+w*x[r]][k+w*y[r]]=true;
                    f[i][j+a[i]*x[r]][k+a[i]*y[r]]|=1<<((r+1)%8);
                    f[i][j+a[i]*x[r]][k+a[i]*y[r]]|=1<<((r+7)%8);
                }
    }
    for (int i=0;i<500;i++) for (int j=0;j<500;j++) ans+=t[i][j];
    cout << ans << endl;
}