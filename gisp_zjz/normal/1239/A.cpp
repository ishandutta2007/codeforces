#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+6;
const int M=1000000007;
int f[maxn],n,m,ans;

int main(){
    f[1]=1; f[2]=2;
    for (int i=3;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%M;
    cin >> n >> m;
    ans=f[n]+f[m]-1;
    if (ans<0) ans+=M; if (ans>=M) ans-=M;
    cout << ans*2%M << endl;
}