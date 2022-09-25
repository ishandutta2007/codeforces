#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
int arr[2005][2005];
int pref[2005][2005];
int hor[2005][2005];
int ver[2005][2005];
void print(){
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            printf("%d ",arr[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            printf("%d ",pref[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            printf("%d ",hor[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            printf("%d ",ver[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for (int x=1;x<=n;x++){
        getchar();
        for (int y=1;y<=n;y++){
            arr[x][y]=(getchar()=='B'?1:0);
        }
    }
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            pref[x][y]=pref[x-1][y]+pref[x][y-1]-pref[x-1][y-1]+arr[x][y];
        }
    }
    for (int x=1;x<=n;x++){ ///horizontal
        for (int y=k;y<=n;y++){
            if (pref[x][n]-pref[x-1][n]) hor[x][y]=(pref[x][n]-pref[x-1][n]==pref[x][y]-pref[x][y-k]-pref[x-1][y]+pref[x-1][y-k]);
        }
    }
    for (int x=k;x<=n;x++){ ///horizontal
        for (int y=1;y<=n;y++){
            if (pref[n][y]-pref[n][y-1]) ver[x][y]=(pref[n][y]-pref[n][y-1]==pref[x][y]-pref[x][y-1]-pref[x-k][y]+pref[x-k][y-1]);
        }
    }
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            hor[x][y]+=hor[x-1][y];
        }
    }
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            ver[x][y]+=ver[x][y-1];
        }
    }
    //print();
    int ans=0;
    for (int x=k;x<=n;x++){
        for (int y=k;y<=n;y++){
            ans=max(ans,hor[x][y]-hor[x-k][y]+ver[x][y]-ver[x][y-k]);
        }
    }
    for (int x=1;x<=n;x++){
        if (pref[x][n]==pref[x-1][n]) ans++;
        if (pref[n][x]==pref[n][x-1]) ans++;
    }
    printf("%d\n",ans);
}