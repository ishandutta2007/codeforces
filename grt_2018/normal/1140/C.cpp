#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int MAXN = 3*1000*100+1;
int n,k;
long long ans;
long long s;
pair<int,int>t[MAXN];
priority_queue<int>Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n;i++) {
        cin>>t[i].ND>>t[i].ST;
    }
    sort(t,t+n);
    reverse(t,t+n);
    for(int i=0; i<k;i++) {
        s+=t[i].ND;
        ans=max(ans,(long long)s*t[i].ST);
        Q.push(-t[i].ND);
    }
    ans = max(ans,(long long)s*t[k-1].ST);
    for(int i=k; i<n;i++) {
        Q.push(-t[i].ND);
        s+=t[i].ND;
        int tmp = -Q.top();
        Q.pop();
        s-=tmp;
        ans=max(ans,(long long)s*t[i].ST);
        //cout<<"W : "<<s<<" "<<tmp<<"\n";
    }
    cout<<ans;
}