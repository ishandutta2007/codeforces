#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        vector<int> v1,v2;
        for(int i = 0;i<mid;i++)v1.pb(a[i]);
        for(int i = mid;i<n;i++)v2.pb(a[i]);
        int ok=1;
        if(v1.size()>=v2.size()){
            ok=0;
        }
        else{
            reverse(v2.begin(),v2.end());
            while(v2.size()>v1.size()+1)v2.pop_back();
            reverse(v2.begin(),v2.end());
            for(int i = 0;i<v1.size();i++){
              
                if(v1[i]>=v2[i]||v1[i]>=v2[i+1]){
                    ok=0;
                    break;
                }
            }
        }
        if(ok)Min=mid;
        else Max=mid;

    }
    printf("%d\n",Min);
    vector<int> v1,v2;
    for(int i = 0;i<Min;i++)v1.pb(a[i]);
    for(int i = Min;i<n;i++)v2.pb(a[i]);
    vector<int> ans;
    reverse(v2.begin(),v2.end());
    while(v2.size()>v1.size()+1)ans.pb(v2.back()),v2.pop_back();
    reverse(v2.begin(),v2.end());
    for(int i = 0;i<v1.size();i++){
        ans.pb(v2[i]);
        ans.pb(v1[i]);
    }
    ans.pb(v2.back());
    for(auto it:ans){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/