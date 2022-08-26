#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll M=1500000;
int n;
ll p,q,r,ans[maxn],x[maxn],y[maxn],a[maxn];

ll dis(ll u,ll v){
    return u*u+v*v;
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++) scanf("%I64d%I64d",&x[i],&y[i]);
    for (int i=0;i<n;i++) a[i]=i;
    for (int i=0;i<100;i++){
        random_shuffle(a,a+n);
        p=0; q=0;
        for (int j=0;j<n;j++){
            r=a[j];
            if (dis(p+x[r],q+y[r])<dis(p-x[r],q-y[r])) {
                ans[r]=1;
                p+=x[r]; q+=y[r];
            }
            else {
                ans[r]=-1;
                p-=x[r]; q-=y[r];
            }
        }
        if (dis(p,q)>M*M) continue;
        for (int j=0;j<n;j++) printf("%I64d ",ans[j]); printf("\n"); return 0;
    }
}