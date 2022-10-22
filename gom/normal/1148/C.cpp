#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> TP;
const int N=7e5+5;
const ll MOD=1e9+7;
int n,a[N],to[N];
vector<int> v;
void doSwap(int i,int j)
{
    swap(a[i],a[j]);
    to[a[i]]=i; to[a[j]]=j;
    if(2*abs(i-j)>=n){
        v.push_back(i); v.push_back(j);
        return;
    }
    int s1,s2;
    if(i-1>n-i) s1=1;
    else s1=n;
    if(j-1>n-j) s2=1;
    else s2=n;
    if(s1==s2){
        v.push_back(i); v.push_back(s1);
        v.push_back(j); v.push_back(s1);
        v.push_back(i); v.push_back(s1);
    }
    else{
        v.push_back(i); v.push_back(s1);
        v.push_back(j); v.push_back(s2);
        v.push_back(s1); v.push_back(s2);
        v.push_back(i); v.push_back(s1);
        v.push_back(j); v.push_back(s2);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        to[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(i==a[i]) continue;
        int j=to[i];
        doSwap(i,j);
    }
    cout<<v.size()/2<<"\n";
    for(int i=0;i<v.size();i+=2) cout<<v[i]<<" "<<v[i+1]<<"\n";
    return 0;
}