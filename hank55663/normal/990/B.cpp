#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        v.pb(a);
    }
    sort(v.begin(),v.end());
    int j=0;
    int ans=0;
    for(int i=1;i<v.size();i++){
        while(v[i]>v[j]&&v[i]>v[j]+k)
        ans++,j++;
        while(v[i]>v[j]&&v[i]<=v[j]+k)
        j++;
    }
    ans+=v.size()-j;
    printf("%d\n",ans);
}