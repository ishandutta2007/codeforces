#include<iostream>
#include<deque>
using namespace std;
int n;
long double a[100001],b[100001],dp[100001];
long double m(int j,int k){
    return (dp[j]-dp[k])/(b[j]-b[k]);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    deque<int>q;
    q.push_back(1);
    for(int i=1; i<=n ;i++) cin >> a[i];
    for(int i=1; i<=n ;i++) cin >> b[i];
    for(int i=2; i<=n ;i++){
        while(q.size()>=2 && m(q[0],q[1])>0-a[i]) q.pop_front();
        dp[i]=dp[q[0]]+a[i]*b[q[0]];
        while(q.size()>=2 && m(q[q.size()-2],q.back())<m(q.back(),i)) q.pop_back();
        q.push_back(i);
    }
    cout << (long long)dp[n] << endl;
}