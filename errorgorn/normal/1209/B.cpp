#include <cstdio>
#include <algorithm>
using namespace std;
int n;
bool arr[105];
int a[105];
int b[105];
int m=0;
int main(){
    scanf("%d",&n);
    getchar();
    for (int x=0;x<n;x++){
        arr[x]=getchar()=='1';
    }
    for (int x=0;x<n;x++){
        scanf("%d%d",&a[x],&b[x]);
    }
    int curr;
    for (int x=0;x<10000;x++){
        curr=0;
        for (int y=0;y<n;y++){
            if (b[y]<=x && (x-b[y])%a[y]==0){
                arr[y]^=true;
            }
            curr+=arr[y];
        }
        m=max(m,curr);
    }
    printf("%d\n",m);
}