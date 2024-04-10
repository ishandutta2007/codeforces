#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
#define SIZE 100005
int a[SIZE]={0},b[10][SIZE]={0};
char c[SIZE];
int main()
{
    int n,k,w;
    scanf("%d%d%d",&n,&k,&w);
    scanf("%s",c);
    for (int i=1;i<=k;i++){
        b[i%k][i]=c[i-1]-'0';
        a[i]+=a[i-1]+c[i-1]-'0';
    }
    for (int i=k+1;i<=n;i++){
        a[i]+=a[i-1]+c[i-1]-'0';
        //b[i%k][i]
        if (c[i-1]=='0') b[i%k][i]+=b[i%k][i-k];
        else b[i%k][i]+=b[i%k][i-k]+1;
    }
    while(w--){
        int l,r,re;
        scanf("%d%d",&l,&r);
        re=(a[r]-a[l-1])+(r+1-l)/k-2*(b[r%k][r]-b[r%k][l-1]);  
        printf("%d\n",re);
    }
    return 0;
}