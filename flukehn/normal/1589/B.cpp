#include<bits/stdc++.h>
using namespace std;
long long work(){
    long long n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    long long t=n*m/3,w=n*m%3;
    if(w==1){
        t--;
        w+=3;
    }
    return t+w/2;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<work()<<"\n";
    }
}