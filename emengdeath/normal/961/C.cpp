#include<bits/stdc++.h>
using namespace std;
const int N=101;
char a[4][N][N];
auto b=a[0];
int c[4];
int n,ans;
void read(){
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>b[i][j],b[i][j]-='0';
}
int get(bool bz){
    int s=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (b[i][j]!=((i&1)^bz^(j&1))){
                s++;
            }
    return s;
}
void dfs(int x){
    if (x==4){
        for (int i=0;i<2;i++){
            b=a[c[0]];
            int s=get(i);
            b=a[c[1]];
            s+=get(i^(n&1));
            b=a[c[2]];
            s+=get(i^(n&1));
            b=a[c[3]];
            s+=get(i);
            ans=min(ans,s);
        }
        return;
    }
    for (int i=0;i<4;i++)
        if (c[i]==-1){
            c[i]=x;
            dfs(x+1);
            c[i]=-1;
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    ans=n*n*4;
    for (int i=0;i<4;i++){
        b=a[i];
        read();
        c[i]=-1;
    }
    dfs(0);
    cout<<ans;
    return 0;
}