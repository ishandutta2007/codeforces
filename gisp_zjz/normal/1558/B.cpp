#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=4e6+10;
int sum,f[maxn],dp[maxn],n,m;
void add(int &x,int y){x+=y;if (x>=m)x-=m;}
void sub(int &x,int y){x-=y;if (x<0) x+=m;}
int main(){
    cin >> n >> m;
    dp[1]=1;
    for (int i=1;i<=n;i++){
        add(f[i],f[i-1]);
        dp[i]=sum;
        add(dp[i],f[i]);
        if (i==1) dp[i]=1;
        add(sum,dp[i]);
        for (int j=2;j*i<=n;j++){
            add(f[i*j],dp[i]);
            if (i*j+j<=n) sub(f[i*j+j],dp[i]);
        }
    }
    cout << dp[n] << endl;
}