#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    int a[105];
    int l[105];
    vector<int> v;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        scanf("%d",&l[i]);
        if(!l[i])v.pb(a[i]);
    }
    sort(v.begin(),v.end());
  //  reverse(v.begin(),v.end());
    for(int i = 0;i<n;i++){
        if(!l[i]){
            a[i]=v.back();
            v.pop_back();
        }
    }
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}