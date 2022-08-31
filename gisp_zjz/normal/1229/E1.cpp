#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000000007;
ll dp[1111111],a[6][6],n,ans,f[3][6];
int id[6][6][6],cnt;
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
void add(ll &x,ll y){x+=y;if (x>=M)x-=M;}
bool check(int x,int y,int z){
    if (f[0][x]&&f[1][y]&&f[2][z]) return 1;
    if (f[0][x]&&f[2][y]&&f[1][z]) return 1;
    if (f[1][x]&&f[0][y]&&f[2][z]) return 1;
    if (f[1][x]&&f[2][y]&&f[0][z]) return 1;
    if (f[2][x]&&f[0][y]&&f[1][z]) return 1;
    if (f[2][x]&&f[1][y]&&f[0][z]) return 1;
    return 0;
}
int main(){
    for (int i=0;i<6;i++)
        for (int j=i+1;j<6;j++)
            for (int k=j+1;k<6;k++)
                id[i][j][k]=cnt++;
    cin >> n;
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        cin >> a[i][j];
        a[i][j]=a[i][j]*pow_(100,M-2)%M;
    }
    for (int i=n;i<6;i++) a[i][i]=1;
    for (int i=0;i<(1<<18);i++){
        ll res=1;
        for (int j=0;j<18;j++){
            if (i&(1<<j)) f[j/6][j%6]=1,res=res*a[j/6][j%6]%M;
            else f[j/6][j%6]=0,res=res*(M+1-a[j/6][j%6])%M;
        }
        int mask=0;
        for (int x=0;x<6;x++)
        for (int y=x+1;y<6;y++)
        for (int z=y+1;z<6;z++)
            if (check(x,y,z)) {
                int xx,yy,zz,pos=0;
                while (pos==x||pos==y||pos==z) pos++; xx=pos++;
                while (pos==x||pos==y||pos==z) pos++; yy=pos++;
                while (pos==x||pos==y||pos==z) pos++; zz=pos++;
                mask|=1<<id[xx][yy][zz];
            }
            //if(res)cout<<mask<<endl;
        add(dp[mask],res);
    }
    for (int j=0;j<20;j++)
    for (int i=0;i<(1<<20);i++)
        if (i&(1<<j)) add(dp[i],dp[i^(1<<j)]);
    for (int i=0;i<(1<<18);i++){
        ll res=1;
        for (int j=0;j<18;j++){
            if (i&(1<<j)) f[j/6][j%6]=1,res=res*a[3+j/6][j%6]%M;
            else f[j/6][j%6]=0,res=res*(M+1-a[3+j/6][j%6])%M;
        }
        int mask=0;
        for (int x=0;x<6;x++)
        for (int y=x+1;y<6;y++)
        for (int z=y+1;z<6;z++)
            if (check(x,y,z)) mask|=1<<id[x][y][z];
        //if (res)cout<<"H"<<res<<' '<<mask<<' '<< dp[mask]<<endl;
        add(ans,dp[(1<<20)-1-mask]*res%M);
    }
    cout << (M+1-ans)%M << endl;
}