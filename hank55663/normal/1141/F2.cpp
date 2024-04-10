#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int main(){
    map<int,vector<pii> > m;
    int n;
    scanf("%d",&n);
    int a[1550];
    for(int i = 1 ;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i = 1 ; i<=n;i++){
        int sum = 0;
        for(int j = i;j>=1;j--){
            sum +=a[j];
            if(m[sum].empty()||m[sum].back().y<j){
                m[sum].pb(mp(j,i));
            }
        }
    }
    vector<pii> ans;
    for(auto it:m){
        if(it.y.size()>ans.size())
            ans=it.y;
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d %d\n",it.x,it.y);
}