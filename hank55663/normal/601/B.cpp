#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
struct node{
    int n,v;
};
int n;
node a[100][100100];
long long int find(int l,int r){
    if(l>r)
    return 0;
    if(l==r)
    return a[0][l-1].v;
    int leng=r-l+1;
    int A=1,i=0;
    for(;A<=leng;A*=2,i++);
    i--;
    A/=2;
    long long int n,ans;
    if(a[i][l-1].v>a[i][r-A].v){
        n=a[i][l-1].n;
        ans=a[i][l-1].v;
    }
    else{
        n=a[i][r-A].n;
        ans=a[i][r-A].v;
    }
    n++;
    return ans*(r-n+1)*(n-l+1)+find(l,n-1)+find(n+1,r);
}
main(){
    int q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
    scanf("%d",&a[0][i].v);
    for(int i=0;i<n-1;i++){
        a[0][i].v=abs(a[0][i+1].v-a[0][i].v);
        a[0][i].n=i;
    }
    a[0][n-1].v=0;
    for(int i=1,j=2;j<=n;i++,j*=2){
        for(int k=0;k<n-j+1;k++){
            if(a[i-1][k].v>a[i-1][k+j/2].v){
                a[i][k].v=a[i-1][k].v;
                a[i][k].n=a[i-1][k].n;
            }
            else{
                a[i][k].v=a[i-1][k+j/2].v;
                a[i][k].n=a[i-1][k+j/2].n;
            }
        }
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        r--;
        printf("%I64d\n",find(l,r));
    }
}