#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> v;
        int a[200005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        v.pb(a[0]);
        LL ans=0;
        for(int i = 1;i<n;i++){
            if((a[i]^v.back())<0){
                sort(v.begin(),v.end());
                ans+=v.back();
                v.clear();
            }
            v.pb(a[i]);
        }
        sort(v.begin(),v.end());
        ans+=v.back();
        printf("%lld\n",ans);
    }
}