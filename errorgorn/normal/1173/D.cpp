#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> v[200005];
int fac[200005];
bool visited[200005];
const int mod=998244353;
int factorial(int i){
    if (fac[i]!=-1) return fac[i];
    else return fac[i]=(((long long)i)*factorial(i-1))%mod;
}
int dp(int i){
    visited[i]=true;
    long long ans=1;
    int children=1;
    for (vector<int>::iterator it=v[i].begin();it!=v[i].end();it++){
        if (!visited[*it]){
            ans*=dp(*it);
            ans%=mod;
            children++;
        }
    }
    ans*=factorial(children);
    ans%=mod;
    return ans;
}
int main(){
    memset(fac,-1,sizeof(fac));
    fac[1]=1;
    scanf("%d",&n);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1]=true;
    long long ans=n;
    int children=0;
    for (vector<int>::iterator it=v[1].begin();it!=v[1].end();it++){
        ans*=dp(*it);
        ans%=mod;
        children++;
    }
    ans*=factorial(children);
    ans%=mod;
    printf("%d\n",ans);
}