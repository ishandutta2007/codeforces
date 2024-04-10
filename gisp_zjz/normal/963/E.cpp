#include <bits/stdc++.h>
using namespace std;

typedef long double db;
const int M=1000000007;
typedef long long ll;
ll a[405][405],ans[405],p1,p2,p3,p4,R;
ll md[105][105][105];
ll pow_(ll x,ll y){ll ret=1;while (y){if (y&1) ret=ret*x%M;x=x*x%M;y>>=1;}return ret;}
ll inv(ll x){return pow_(x,M-2);}
void add(ll &x,ll y){x+=y;if (x>=M) x-=M;}
void sub(ll &x,ll y){x-=y;if (x<0) x+=M;}
void Gauss(int n){
    for (int i=1;i<=n;i++){
        int j=i;
        while (j<n&&a[j][i]==0) ++j;
        for (int k=0;k<=n;k++) swap(a[i][k],a[j][k]);
        for (int j=i+1;j<=n;j++){
            ll res=a[j][i]*inv(a[i][i])%M;
            for (int k=0;k<=n;k++) sub(a[j][k],a[i][k]*res%M);
        }
    }
    for (int i=n;i>=1;i--){
        ans[i]=a[i][0];
        for (int j=i+1;j<=n;j++) sub(ans[i],ans[j]*a[i][j]%M);
        ans[i]=ans[i]*inv(a[i][i])%M;
    }
}
int sqr(int x){return x*x;}
bool check(int x,int y){
    return sqr(x-R-1)+sqr(y-R-1)<=R*R;
}
int main(){
    cin >> R >> p1 >> p2 >> p3 >> p4;
    ll res=inv(p1+p2+p3+p4);
    p1=p1*res%M; p2=p2*res%M; p3=p3*res%M; p4=p4*res%M;
    int n=2*R+1;
    for (int x=1;x<=n;x++)
    for (int y=1;y<=n;y++){
        if (!check(x,y)) continue;
        if (!check(x-1,y)){
            md[x][y][y]=1;
        } else {
            ll Inv=inv(p3);
            for (int i=0;i<=n;i++) {
                ll res=md[x-1][y][i];
                sub(res,md[x-2][y][i]*p1%M);
                sub(res,md[x-1][y-1][i]*p2%M);
                sub(res,md[x-1][y+1][i]*p4%M);
                if (!i) sub(res,1);
                md[x][y][i]=res*Inv%M;
            }
        }
    }
    for (int y=1;y<=n;y++){
        int x=sqrt(sqr(R)-sqr(y-R-1))+R+1;
        for (int i=0;i<=n;i++){
            ll res=md[x][y][i];
            sub(res,md[x-1][y][i]*p1%M);
            sub(res,md[x][y-1][i]*p2%M);
            sub(res,md[x+1][y][i]*p3%M);
            sub(res,md[x][y+1][i]*p4%M);
            if (!i) sub(res,1);
            a[y][i]=res;
        }
        a[y][0]=(M-a[y][0])%M;
    }
    Gauss(n);
    ll Ans=md[R+1][R+1][0];
    for (int i=1;i<=n;i++) add(Ans,md[R+1][R+1][i]*ans[i]%M);
    cout << Ans << endl;
    return 0;
}