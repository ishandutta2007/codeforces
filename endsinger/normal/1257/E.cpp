#include<iostream>
#define I(n) for(int i=1;i<=n;i++)
#define N 200001
using namespace std;
int k1,k2,k3,x,n,ans,m,p[N],q[N],r[N],A,B,C;
int main(){
cin >> k1 >> k2 >> k3;
n = k1+k2+k3;
I(n){cin >> x;if(i<=k1) p[x] = 1;else if(i<=k1+k2) q[x] = 1;else r[x] = 1;}
C = k3;ans = C;
I(n){A += p[i];B += q[i];C -= r[i];m = max(m,A-B);ans = max(ans,B+m+C);}
cout << n-ans;
}