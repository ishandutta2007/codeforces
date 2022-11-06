#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 200000
#define mo 1000000007
#define ll long long
using namespace std;
int n,p[mx];ll a[mx][2][3];
int main(){
    scanf("%d",&n);
    rep(i,2,n)scanf("%d",&p[i]);
    dep(i,n,1){int s=p[i];
        a[i][0][2]=a[i][0][2]*2%mo;
        a[i][1][1]=a[i][1][1]*2%mo;
        a[i][1][2]=a[i][1][2]*2%mo;
        ll x=(a[i][0][0]+a[i][0][2])%mo;
        ll y=(a[i][1][0]+a[i][1][1]+a[i][1][2]+1)%mo;
        if(i==1){
            printf("%I64d\n",(x+y)%mo);break;
        }
        ll s1=a[s][0][0],s3=a[s][0][2];
        ll s4=a[s][1][0],s5=a[s][1][1],s6=a[s][1][2];       
        a[s][0][0]=(s1+s5*y+y)%mo;
        a[s][0][2]=(s3+s1*x+s3*x+s4*y+s6*y)%mo;
        a[s][1][0]=(s4+s4*x+x)%mo;
        a[s][1][1]=(s5+s1*y)%mo;
        a[s][1][2]=(s6+s3*y+s5*x+s6*x)%mo;
    }
}