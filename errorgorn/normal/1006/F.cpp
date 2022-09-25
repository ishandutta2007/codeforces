#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n,m;
long long k;
long long arr[21][21];
vector<long long> f[22][22],b[22][22];
map<long long,int> fm,bm;
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            scanf("%lld",&arr[x][y]);
        }
    }
    int s=min(n,m)+1;
    f[1][1].push_back(arr[1][1]);
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            if (x+y>s) continue;
            for (int z=0;z<f[x-1][y].size();z++){
                f[x][y].push_back(f[x-1][y][z]^arr[x][y]);
            }
            for (int z=0;z<f[x][y-1].size();z++){
                f[x][y].push_back(f[x][y-1][z]^arr[x][y]);
            }
        }
    }
    b[n][m].push_back(arr[n][m]^k);
    for (int x=n;x>=1;x--){
        for (int y=m;y>=1;y--){
            if (x+y<s) continue;
            for (int z=0;z<b[x+1][y].size();z++){
                b[x][y].push_back(b[x+1][y][z]^arr[x][y]);
            }
            for (int z=0;z<b[x][y+1].size();z++){
                b[x][y].push_back(b[x][y+1][z]^arr[x][y]);
            }
        }
    }
    long long ans=0;
    for (int y=1;y<=min(n,m);y++){
        int x=s-y;
        fm.clear();
        bm.clear();
        for (int z=0;z<f[x][y].size();z++){
            fm[f[x][y][z]]++;
        }
        for (int z=0;z<b[x][y].size();z++){
            bm[b[x][y][z]^arr[x][y]]++;
        }
        for (map<long long,int>::iterator it=fm.begin();it!=fm.end();it++){
            ans+=((long long)(*it).second)*bm[(*it).first];
        }
    }
    printf("%lld\n",ans);
}