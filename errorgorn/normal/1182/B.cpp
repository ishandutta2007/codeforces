#include <cstdio>
using namespace std;
char arr[505][505];
int h[505];
int w[505];
int _x=-1,_y=-1;
int k;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++){
        getchar();
        for (int y=0;y<m;y++){
            arr[x][y]=getchar();
            if (arr[x][y]=='*'){
                h[x]++;
                w[y]++;
                if (h[x]>1) _x=x;
                if (w[y]>1) _y=y;
                k++;
            }
        }
    }
    if (_x==-1 || _y==-1 || _x==0 || _x==n-1 || _y==0 || _y==n-1 ||
        arr[_x-1][_y]=='.' || arr[_x+1][_y]=='.' || arr[_x][_y-1]=='.' || arr[_x][_y+1]=='.'){
        printf("NO\n");
        return 0;
    }
    int __x,__y;
    __x=_x-1;
    while (__x!=-1 && arr[__x][_y]=='*'){
        k--;
        __x--;
    }
    __x=_x+1;
    while (__x!=n && arr[__x][_y]=='*'){
        k--;
        __x++;
    }
    __y=_y-1;
    while (__y!=-1 && arr[_x][__y]=='*'){
        k--;
        __y--;
    }
    __y=_y+1;
    while (__y!=m && arr[_x][__y]=='*'){
        k--;
        __y++;
    }
    if (k==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}