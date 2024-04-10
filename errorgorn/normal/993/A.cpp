#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[9];
int brr[9];
int a[5];
int b[5];
bool ina(int i,int j){
    return a[0]<=i && i<=a[1] && a[2]<=j && j<=a[3];
}
int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
bool inb(int i,int j){
    if (dist(i,j,brr[0],brr[1])>b[1]-b[0]) return false;
    if (dist(i,j,brr[2],brr[3])>b[1]-b[0]) return false;
    if (dist(i,j,brr[4],brr[5])>b[1]-b[0]) return false;
    if (dist(i,j,brr[6],brr[7])>b[1]-b[0]) return false;
    return true;
}
int main(){
    for (int x=0;x<8;x++) scanf("%d",&arr[x]);
    for (int x=0;x<8;x++) scanf("%d",&brr[x]);

    a[0]=min(min(arr[0],arr[2]),min(arr[4],arr[6]));
    a[1]=max(max(arr[0],arr[2]),max(arr[4],arr[6]));
    a[2]=min(min(arr[1],arr[3]),min(arr[5],arr[7]));
    a[3]=max(max(arr[1],arr[3]),max(arr[5],arr[7]));

    b[0]=min(min(brr[0],brr[2]),min(brr[4],brr[6]));
    b[1]=max(max(brr[0],brr[2]),max(brr[4],brr[6]));
    b[2]=min(min(brr[1],brr[3]),min(brr[5],brr[7]));
    b[3]=max(max(brr[1],brr[3]),max(brr[5],brr[7]));

    for (int x=0;x<4;x++) if (ina(brr[x*2],brr[x*2+1])) {
        printf("YES");
        return 0;
    }
    for (int x=0;x<4;x++) if (inb(arr[x*2],arr[x*2+1])) {
        printf("YES");
        return 0;
    }


    if (inb( (a[0]+a[1])/2 ,(a[2]+a[3])/2  )) {
        printf("YES");
        return 0;
    }


    if (ina( (b[0]+b[1])/2 ,(b[2]+b[3])/2  )) {
        printf("YES");
        return 0;
    }


    printf("NO");
}