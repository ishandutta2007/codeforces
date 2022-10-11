#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;cin>>n>>v;
    int l=0,r=1000;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        l=max(l,x);
        r=min(r,y);
    }
    if(l>r)cout<<-1;
    else if(l<=v&&v<=r)cout<<0;
    else cout<<min(abs(v-l),abs(v-r));
}