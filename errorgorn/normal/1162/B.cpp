#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int arr[55][55][2];
int main(){
    scanf("%d%d",&n,&m);
    for (int z=0;z<2;z++){
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                scanf("%d",&arr[x][y][z]);
            }
        }
    }
    for (int x=0;x<n;x++){
        for (int y=0;y<m;y++){
            if (arr[x][y][0]>arr[x][y][1]) swap(arr[x][y][0],arr[x][y][1]);
        }
    }
    for (int x=0;x<n;x++){
        for (int y=1;y<m;y++){
            if (arr[x][y-1][0]>=arr[x][y][0] || arr[x][y-1][1]>=arr[x][y][1]){
                printf("Impossible\n");
                return 0;
            }
        }
    }
    for (int x=1;x<n;x++){
        for (int y=0;y<m;y++){
            if (arr[x-1][y][0]>=arr[x][y][0] || arr[x-1][y][1]>=arr[x][y][1]){
                printf("Impossible\n");
                return 0;
            }
        }
    }
    printf("Possible\n");
}