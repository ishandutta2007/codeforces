#include<bits/stdc++.h>
using namespace std;
int n,q,a[3][100005],d[100005],s=0;
void Check(int x){
    bool flag=0;
    if(a[1][x]&&a[2][x])flag=1;
    if(a[1][x]&&a[2][x+1])flag=1;
    if(a[1][x+1]&&a[2][x])flag=1;
    if(d[x]!=flag){
        if(!flag)s--;
        else s++;
        d[x]=flag;
    }
}
int main(){
    scanf("%d%d",&n,&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]^=1;
        Check(y);
        Check(y-1);
        if(!s)puts("Yes");
        else puts("No");
    }
}