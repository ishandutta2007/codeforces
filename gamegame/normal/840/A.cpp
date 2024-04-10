#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,m;
pair<int,int>a[200001];
pair<int,int>b[200001];
int ans[200001];
int main(){
    ios::sync_with_stdio(false);
    cin >> m;
    for(int i=1; i<=m ;i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    for(int i=1; i<=m ;i++){
        cin >> b[i].first;
        b[i].second=i;
    }
    sort(a+1,a+m+1);
    sort(b+1,b+m+1);
    for(int i=m; i>=1 ;i--){
        ans[b[i].second]=a[m+1-i].first;
    }
    for(int i=1; i<=m ;i++) cout << ans[i] << ' ';
    cout << endl;
}