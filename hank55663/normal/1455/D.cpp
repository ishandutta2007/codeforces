#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
using namespace std;
int f[505];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    vector<int> v;
    int a[505];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v.pb(a[i]);
    }
    v.pb(x);
    sort(v.begin(),v.end());
    int ans=n+2;
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<=500;j++)f[j]=j;
        vector<int> tmp;
        for(int j = 0;j<v.size();j++){
            if(j!=i)tmp.pb(v[j]);
        }
        set<int> s;
        int cnt=0;
        int ok=1;
        for(int j = 0;j<n;j++){
            if(tmp[j]!=a[j]){
                cnt++;
                if(a[j]<=x)ok=0;
                if(a[j]>v[i])ok=0;
                if(tmp[j]>a[j])ok=0;
               // int a=Find(a[j]);
               // int b=Find(tmp[j]);
                if(s.find(a[j])!=s.end())ok=0;
                s.insert(a[j]);
            }
        }
        
        if(ok)
        ans=min(ans,cnt);
    }
    if(ans==n+2)ans=-1;
//    }
    printf("%d\n",ans);
}  
int main(){
    int t=1;
    scanf("%d",&t);
    //int n;
    while(t--){
        solve();
    }
}