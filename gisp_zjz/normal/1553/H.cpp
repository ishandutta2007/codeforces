#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
const int inf=1e9;
int n,k,mx[21][1<<19],mn[21][1<<19],ans[21][1<<19],sz[21][1<<19];
void Min(int &x,int y){if (y<x)x=y;}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        int x;scanf("%d",&x);
        sz[0][x]++;
        mx[0][x]=mn[0][x]=0;
        ans[0][x]=inf;
    }
    for (int i=0;i<k;i++){
        int d=1<<i;
        for (int j=0;j<(1<<k);j+=d*2){
            sz[i+1][j]=sz[i][j]+sz[i][j+d];
            if (!sz[i+1][j]) continue;
            if (!sz[i][j+d]){ //left only
                for (int r=0;r<d;r++){
                    mx[i+1][j+r]=mx[i][j+r];
                    mn[i+1][j+r]=mn[i][j+r];
                    mx[i+1][j+r+d]=mx[i][j+r]+d;
                    mn[i+1][j+r+d]=mn[i][j+r]+d;
                    ans[i+1][j+r]=ans[i+1][j+r+d]=ans[i][j+r];
                }
            } else if (!sz[i][j]){ //right only
                for (int r=0;r<d;r++){
                    mx[i+1][j+r]=mx[i][j+r+d]+d;
                    mn[i+1][j+r]=mn[i][j+r+d]+d;
                    mx[i+1][j+r+d]=mx[i][j+r+d];
                    mn[i+1][j+r+d]=mn[i][j+r+d];
                    ans[i+1][j+r]=ans[i+1][j+r+d]=ans[i][j+r+d];
                }
            } else {
                for (int r=0;r<d;r++){
                    mx[i+1][j+r]=mx[i][j+r+d]+d;
                    mn[i+1][j+r]=mn[i][j+r];
                    mx[i+1][j+r+d]=mx[i][j+r]+d;
                    mn[i+1][j+r+d]=mn[i][j+r+d];
                    ans[i+1][j+r]=ans[i+1][j+r+d]=min(ans[i][j+r],ans[i][j+r+d]);
                    Min(ans[i+1][j+r],(mn[i][j+r+d]+d)-mx[i][j+r]);
                    Min(ans[i+1][j+r+d],(mn[i][j+r]+d)-mx[i][j+r+d]);
                }
            }
        }
    }
    for (int i=0;i<(1<<k);i++) printf("%d ",ans[k][i]); puts("");
    return 0;
}