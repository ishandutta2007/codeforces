#include<bits/stdc++.h>
#define maxn 2048576

using namespace std;
typedef long long ll;
ll a1[maxn],p[maxn],a2[maxn],q1[maxn],q2[maxn],b[maxn],X,Y,n,r,tmp;
ll c[maxn],d[maxn];

void FWT(ll a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
                a[i+j+d]+=a[i+j];
                //xor:a[i+j]=x+y,a[i+j+d]=(x-y+mod)%mod;
                //and:a[i+j]=x+y;
                //or:a[i+j+d]=x+y;
}

void UFWT(ll a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
                a[i+j+d]-=a[i+j];
}

int main(){
    cin >> n >> X >> Y;
    for (int i=0;i<n;i++) scanf("%I64d",&b[i]);
    if (Y%X){
        printf("0\n");
        return 0;
    }
    tmp=Y;
    for (int j=2;j<=1000000;j++){
        if (tmp%j==0){
            p[++r]=j;
            while (tmp%j==0) tmp/=j,a1[r]++;
        }
    }
    for (int i=0;i<n;i++){
        ll w=__gcd(b[i],tmp);
        if (w>1&&w<tmp) {
            p[++r]=w,a1[r]=1;
            p[++r]=tmp/w,a1[r]=1;
            tmp=1; break;
        }
    }
    if (tmp>1) p[++r]=tmp,a1[r]=1;
    tmp=X;
    for (int i=1;i<=r;i++){
        while (tmp%p[i]==0) a2[i]++,tmp/=p[i];
    }
    //for (int i=1;i<=r;i++) cout<<p[i]<<' '<<a1[i]<<' '<<a2[i]<<endl;
    for (int i=1;i<=r;i++) {
        q1[i]=1; for (int j=0;j<a1[i];j++) q1[i]*=p[i];
        q2[i]=1; for (int j=0;j<a2[i];j++) q2[i]*=p[i];
    }
    for (int i=0;i<n;i++){
        int res=0;
        for (int j=1;j<=r;j++) {
            if (b[i]%q2[j]==0&&((b[i]/q2[j])%p[j])) res|=1<<(j-1);
            if (q1[j]==q2[j]) res|=1<<(j-1);
        }
        if (b[i]%X==0) c[res]++;
        res=0;
        for (int j=1;j<=r;j++) {
            if (b[i]%q1[j]==0&&((b[i]/q1[j])%p[j])) res|=1<<(j-1);
            if (q1[j]==q2[j]) res|=1<<(j-1);
        }
        if (Y%b[i]==0) d[res]++;
    }
    FWT(c,1<<r);
    FWT(d,1<<r);
    for (int i=0;i<(1<<r);i++) c[i]*=d[i];
    UFWT(c,1<<r);
    cout << c[(1<<r)-1] << endl;
}