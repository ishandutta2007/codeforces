#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
double arr[10005][2];
int main(){
    scanf("%d%d",&n,&k);
    arr[0][0]=k;
    double excess;
    int ans=0;
    int a=0,b=1;
    for (int x=0;x<n;x++){
        for (int y=0;y<=x;y++){
            if (arr[y][a]>=0.999999){
                ans++;
                excess=arr[y][a]-1;
                excess/=2;
                arr[y][b]+=excess;
                arr[y+1][b]+=excess;
            }
            arr[y][a]=0;
        }
        swap(a,b);
    }
    printf("%d\n",ans);
}