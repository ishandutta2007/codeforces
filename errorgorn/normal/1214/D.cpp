#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> grid[1000005];
int arr[2000005];
int main(){
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++){
        getchar();
        for (int y=0;y<m;y++){
            grid[x].push_back(getchar());
        }
        grid[x].push_back('$');
    }
    for (int y=0;y<=m;y++) grid[n].push_back('$');
    grid[0][0]='*';
    for (int x=0;x<n;x++){
        for (int y=0;y<m;y++){
            if (grid[x][y]=='*'){
                if (grid[x+1][y]=='.') grid[x+1][y]='*';
                if (grid[x][y+1]=='.') grid[x][y+1]='*';
            }
        }
    }
    grid[n-1][m-1]='%';
    for (int x=n-1;x>=0;x--){
        for (int y=m-1;y>=0;y--){
            if (grid[x][y]=='%'){
                arr[x+y]++;
                if (x && grid[x-1][y]=='*') grid[x-1][y]='%';
                if (y && grid[x][y-1]=='*') grid[x][y-1]='%';
            }
        }
    }
    int ans=3;
    for (int x=1;x<n+m-2;x++){
        ans=min(ans,arr[x]);
    }
    printf("%d\n",ans);
}