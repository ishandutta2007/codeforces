#include<bits/stdc++.h>
#define maxn 2000005

using namespace std;
typedef long long ll;
const ll M=1000000007;
int p[maxn],a[maxn],n,prime[maxn],ans,d,t,c[maxn],cc[maxn];
bool f[maxn],ff[maxn],g;
vector <int> h[maxn];

void prime_sieve(){
    p[1]=1; t=0;
    for (int i=2;i<maxn;i++){
        if (!p[i]) prime[++t]=i;
        for (int j=1;j<=t;j++){
            if (1ll*prime[j]*i>=maxn) break;
            p[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}
bool check(ll x){
    if (x>=maxn) return false;
    for (int i=1;x*i<maxn;i++) if (f[x*i]) return true;
    return false;
}
int cnt(int x){
    int res=0; for (int i=1;i*x<maxn;i++) res+=c[i*x]; return res;
}

int main(){
    prime_sieve();
    for (int i=1;i<=t;i++)
        for (int j=1;j*prime[i]<maxn;j++)
            h[j*prime[i]].push_back(prime[i]);
    cin >> n;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n); ans=1;
    for (int i=n-1;i>=0;i--){
        if (!f[a[i]]) f[a[i]]=true,c[a[i]]++;
        else {
            int tt=a[i]-1; f[tt]=true,c[tt]++;
            for (int j=0;j<h[tt].size();j++) f[h[tt][j]]=true;
        }
    }
    for (int i=2;i<maxn;i++) if (c[t]>1) g=true;
    if (c[1]) g=true;
    for (int i=1;i<=t;i++){
        int r=prime[i],x=1;
        while (check(1ll*x*prime[i])) x=x*prime[i];
        ans=1ll*x*ans%M;
        if (x==1) continue;
        a[prime[i]]=x; cc[prime[i]]=cnt(x);
        //if (x>1)cout<<prime[i]<<' '<<cc[prime[i]]<<endl;
    }
    //for (int i=2;i<=5;i++)cout<<c[i]<<' ';cout<<endl;
    //cout<<g<<endl;
    if (!g){
        for (int i=2;i<maxn;i++) if (c[i]){
            //cout<<i<<endl;
            bool flag=true;
            for (int j=0;j<h[i].size();j++){
                int P=h[i][j];
                //cout<<'!'<<P<<endl;
                if (i%a[P]==0&&cc[P]==1) flag=false;
            }
            if (flag){
                g=true;
                break;
            }
        }
    }
    cout << (ans+g)%M << endl;
}