#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int>T[10001];
int ans=1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    pair<int,int>last={0,0};
    for(int i=1; i<=n;i++) {
        cin>>T[i].first>>T[i].second;
        //if(T[i]==last) continue;
        int pom=min(T[i].first,T[i].second)-max(last.first,last.second)+1;
        if(last.first==last.second) pom--;
        ans+=max(pom,0);
        last=T[i];
    }
    //if(last.first==0&&last.second==0) ans++;
    cout<<ans;
    return 0;
}