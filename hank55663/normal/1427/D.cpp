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
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[52];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    vector<vector<int> > ans;
    for(int i = 0;i<n;i++){
        if(i==n-1&&n%2==1)break;
        for(int j =0;j<n;j++){
            if(a[j]==i){
                if(i%2==0){
                    vector<int> tmp;
                    int tot=n;
                    for(int k=0;k<i;k++)tmp.pb(1);
                    if(j-i+1)
                    tmp.pb(j-i+1);
                    tot-=j-i+1;
                    tot-=i;
                    if(tot)tmp.pb(tot);
                    ans.pb(tmp);
                }
                else{
                    vector<int> tmp;
                    int tot=n;
                    for(int k=0;k<i;k++)tmp.pb(1);
                    tot-=i;
                    tot-=j;
                    if(tot)
                    tmp.pb(tot);
                    //tmp.pb(j);
                    if(j)tmp.pb(j);
                    reverse(tmp.begin(),tmp.end());
                    ans.pb(tmp);
                }
                break;
            }
           // printf("%d %d\n",i,j);
        }
        if(ans.back().size()==1){
            ans.pop_back();
            continue;
        }
        //printf()
        vector<vector<int> > v;
        int now=0;
        for(auto it:ans.back()){
            vector<int> tt;
            for(int i = 0;i<it;i++){
                tt.pb(a[now]);
             //   printf("%d %d\n",a[now],now);
                now++;
            }
            v.pb(tt);
        }
        reverse(v.begin(),v.end());
         now=0;
        for(auto it:v){
            for(auto it2:it){
                a[now++]=it2;
               // printf("%d ",it2);
            }
        }
     //   for(int j = 0;j<n;j++)printf("%d ",a[j]+1);
       // printf("\n");
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d ",it.size());
        for(auto it2:it){
            printf("%d ",it2);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/