#include<bits/stdc++.h>
using namespace std;
int work(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i)if(a[i]>b[i]||a[i]+1<b[i])return 0;
    return 1;  
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<(work()?"YES":"NO")<<"\n";
    }
}