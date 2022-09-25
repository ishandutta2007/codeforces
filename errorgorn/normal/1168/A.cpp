#include <cstdio>
using namespace std;
int n,m;
int arr[300005];
bool check(int i){
    //printf("\n");
    //printf("%d: ",i);
    int prev=0;
    for (int x=0;x<n;x++){
        if (arr[x]>=prev){
            if (m+prev-arr[x]>i) prev=arr[x];
        }
        else if (arr[x]<prev){
            if (prev-arr[x]>i) return false;
        }
        //printf("%d ",prev);
    }
    return true;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    int a=0,b=m,c;
    while (a!=b){
        c=(a+b)>>1;
        if (check(c)){
            b=c;
            if (c==0 || !check(c-1)){
                a=c;
            }
        }
        else{
            a=c+1;
        }
    }
    printf("%d\n",a);
}