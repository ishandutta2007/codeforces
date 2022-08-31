#include<bits/stdc++.h>
#define maxn 23405

using namespace std;
typedef long long ll;
const int E=65535;
ll M,m,X,a[maxn],b[maxn],p[maxn],ans,j,t;
ll A[60][maxn],P[60][maxn],T[60];
ll mut(ll x,ll y){
    ll rt=0,tt=x;
    while (y){
        rt=(rt+tt*(y&0xffff))%M;
        tt=(tt<<16)%M;
        y>>=16;
    }
    return rt;
}
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=mut(rt,x); x=mut(x,x); y>>=1;
    }
    return rt;
}
void dfs(int x){
    if (x==t){
        ll w=1,res=1;M=1;
        for (int i=0;i<t;i++) for (int j=0;j<b[i];j++){
            if (j) w*=p[i]; else w*=(p[i]-1);
            M*=p[i];
        }
        //cout<<w<<' '<<M<<endl;
        for (int i=0;i<t;i++)
            for (int j=0;j<b[i]-1;j++)
                if (pow_(X,w/p[i])==1)
                    w/=p[i],res*=p[i];
        //cout<<res<<endl;
        for (int i=0;i<t;i++) if (b[i]){
            for (int I=0;I<T[i];I++)
                for (int j=0;j<A[i][I];j++)
                    if (pow_(X,w/P[i][I])==1)
                        w/=P[i][I],res*=P[i][I];
        }
        //cout<<res<<endl;
        ans+=res;
    }
    else {
        for (int i=0;i<=a[x];i++) b[x]=i,dfs(x+1);
    }
}
int main(){
    cin >> m >> X;
    if (X==1) {
        cout << m << endl; return 0;
    }
    j=2;
    t=-1;
    while (j*j<=m){
        if (m%j==0){
            t++; p[t]=j;
            while (m%j==0) a[t]++,m/=j;
        }
        j++;
    }
    if (m>1) t++,p[t]=m,a[t]=1;
    t++;
    for (int i=0;i<t;i++){
        m=p[i]-1; j=2; T[i]=-1;
        while (j*j<=m){
            if (m%j==0){
                T[i]++; P[i][T[i]]=j; A[i][T[i]]=0;
                while (m%j==0) A[i][T[i]]++,m/=j;
            }
            j++;
        }
        if (m>1) T[i]++,P[i][T[i]]=m,A[i][T[i]]=1;
        T[i]++;
    }
    dfs(0);
    cout << ans << endl;
}