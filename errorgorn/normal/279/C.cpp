#include <cstdio>
#include <stack>
using namespace std;
int n,q;
int arr[100005];
int left[100005];
int right[100005];
int main(){
    scanf("%d%d",&n,&q);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    int bac=0;
    for (int x=1;x<n;x++){
        if (arr[x]<arr[x-1]){
            for (int y=bac;y<x;y++) right[y]=x-1;
            bac=x;
        }
    }
    for (int y=bac;y<n;y++) right[y]=n-1;
    
    bac=n-1;
    for (int x=n-2;x>=0;x--){
        if (arr[x]<arr[x+1]){
            for (int y=bac;y>x;y--) left[y]=x+1;
            bac=x;
        }
    }
    for (int y=bac;y>=0;y--) left[y]=0;
    
    //for (int x=0;x<n;x++) printf("%d %d\n",left[x],right[x]);

    int a,b;
    while (q--){
        scanf("%d%d",&a,&b);
        a--,b--;
        if (right[a]>=left[b]) printf("Yes\n");
        else printf("No\n");
    }
}